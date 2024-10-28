#!/bin/bash
tmpf=$(mktemp)
./.compute.py > $tmpf
diff $tmpf ./origin.txt
exit $?
rm $tmpf
