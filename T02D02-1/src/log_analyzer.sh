#!/bin/bash

if [ $1 ]
then
	fn=$(basename $1)
	if [[ -e $fn && "$fn" =~ \.log$ ]]
	then
		echo "$(wc -l $fn | awk '{print $1}') $(cat $fn | awk '{print $1}' | xargs basename | sort | uniq | wc -l | awk '{print $1}') $(cat $fn | awk '{print $8}' | uniq | expr $(wc -l) - 1)"
	else
		echo "Файл $fn не существует или это не файл журнала!"
	fi
else
	echo "Отсутствует аргумент скрипта (путь к файлу)!"
fi
