#!/bin/bash
# LAB 2

shopt -s extglob

vector_d=($(find . -type d -name gr[0-9][0-9]_lab01 | sort))

echo "${vector_d[@]}"

lenght_v=${#vector_d[*]}
let "l_v = $lenght_v -1"
echo $l_v
lenght_hostR=6

path=$(pwd)

for i in $(seq 0 1 $l_v) 
do
echo "$i\n"

    if [[ -d ${vector_d[i]}/es02/ ]]
        then

        echo "Directory es02 exists."


        if [[ -f ${vector_d[i]}/es02/es02.sh ]]
            then

            echo "Directory es02 exists, file es02.sh: test passed."

            cp "host.txt" "${vector_d[i]}/es02"

            echo "written"

            cd ${vector_d[i]}/es02
            
            rm -v !("es02.sh"|"host.txt")

            chmod +x ./es02.sh
            
            ./es02.sh

            cd $path

            if [[ -f ${vector_d[i]}/es02/hostRenamed.txt ]]
            then
            echo "The file hostReanmed.txt was generated."
            diff_v=$(diff "hostRenamed.txt" "${vector_d[i]}/es02/hostRenamed.txt" | grep "<" | wc -l )

            #echo ${diff_v[@]}

            if [[ $diff_v == "" ]]
            then
                echo "No differences found, everything OK, except my life."
            else
                if [[ $diff_v == "0" ]]
                then
                    echo "No diffences in changes found."
                    #righe aggiunte


                else
                    echo "Found $diff_v differences of line changed."
                
                fi

                echo "Differences found."

            fi

            else

            echo "The file hostRenamed.txt wasn't generated."

            fi


        else

           echo "Neither directory es02 or file es02.sh exist, test failed."

        fi

    else
        echo "Directory es02 doesn't exist, test failed."

    fi

  

done


