# EncryptedDialog

本题是 AI 交互题。你只能用英语来和它交流（更准确地说，只能使用 ASCII 可打印字符）。

你向 AI 输入的内容将会被一个「输入码表」转换成密文，再发送给 AI 作为输入；AI 的输出又会被一个「输出码表」转换成密文，再显示给你。

你事先无从知道这两份码表，我只能告诉你：码表是由26个英文字母到26个英文字母的一一映射（大小写不敏感）。

你的目标是让 AI 输出一字不差的 `The quick brown fox jumps over the lazy dog.`（注意这里的输出是最终显示到你屏幕上的输出）

## 交互方法

input.json 和 output.json 可以使用 [generate_map.py](generate_map.py) 生成。所有玩家将使用同样的映射表。

大致步骤为：

- 玩家输入内容，如果有非 ASCII 字符，本次输入无效，否则，
- 用 [input.json](input.json) 对输入进行加密，发送给 API。
- 从 API 获得输出。如果有非 ASCII 字符，重新获取输出。
- 用 [output.json](output.json) 对输出进行加密，显示给玩家。
