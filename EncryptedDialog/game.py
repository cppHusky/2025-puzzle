#!.venv/bin/python3
import re
import json
from zhipuai import ZhipuAI as ai
with open('input.json','r')as injson:
	input_map=json.load(injson)
with open('output.json','r')as outjson:
	output_map=json.load(outjson)
with open('APIKEY','r')as key_file:
	api_key=key_file.read().strip()
with open('game.log','w')as log:
	log.write("")
def input_mapping(text):
	return ''.join([input_map.get(char,char)for char in text])
def output_mapping(text):
	return ''.join([output_map.get(char,char)for char in text])
client=ai(api_key=api_key)
MODEL="glm-4-flash"
MESSAGE=[]
def logging_input(message):
	with open('game.log','a')as log:
		log.write("> "+message+'\n')
def logging_output(message):
	with open('game.log','a')as log:
		log.write("< "+message+'\n')
def get_response():
	response=client.chat.completions.create(
		model=MODEL,
		messages=MESSAGE,
		top_p=.7,
		temperature=.95,
		max_tokens=256
	)
	return response.choices[0].message.content
target="The quick brown fox jumps over the lazy dog"
MESSAGE.append({"role":"system","content":"You should only use English for chat with the user. To be more precisely, you can only output the ASCII printable characters."})
while True:
	prompt=input("> ")
	actual_input=input_mapping(prompt)
	MESSAGE.append({"role":"user","content":actual_input})
	actual_response=get_response()
	logging_input(actual_input)
	logging_output(actual_response)
	response=output_mapping(actual_response)
	print("< "+response)
	if response.lower()==target.lower():
		print("Congratulations!")
		break
