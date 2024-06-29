#!/bin/bash

if [[ $1 && $2 && $3 ]]
then
	filename=$1
	fn=$(basename $filename)
        if [ -e $fn ]
	then
                sed -i '' "s/$2/$3/g" $fn
                echo "$filename - $(ls -l $fn | awk '{ print $5 }') - $(date +"%Y-%m-%d %H:%M") - $(shasum -a 256 $fn | awk '{ print $1 }') - sha256" >> files.log
		echo "Замена прошла успешно!"
        else
                echo "Файл $fn не существует!"
        fi
else
	echo "Отсутствует один или несколько аргументов скрипта (путь к файлу, строка для замены, замена)!"
fi
