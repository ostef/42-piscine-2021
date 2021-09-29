#!/bin/sh

VAR1=`echo $FT_NBR1 | sed 'y/'\''\\"?!/01234/'`
VAR2=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
BASE5=`echo "ibase=5;$VAR1+$VAR2" | bc`
echo "obase=13;$BASE5" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
