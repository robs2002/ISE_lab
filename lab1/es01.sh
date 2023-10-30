#!/bin/bash

comando=$1 #read what command has to execute
argomento1=$2 #read first argument
argomento2=$3 #read second argument
argomento3=$4 #read third argument
path_iniziale=$(pwd) #see what is the work directory

case $comando in #finding what command to do
    1)  
        echo "You're looking for a file named $argomento1 in the work-directory $path_iniziale."

        #control block
        if [[ $# != 2 ]]; then #controlling number of arguments
            echo "The script for the command $comando needs 2 arguments, retry please."
            exit 0
        fi            
        if [[ $argomento1 != *.* ]]; then #controlling the pattern of the file
            echo "The file $argomento1 is written wrong, try using this pattern: file.ext."
            exit 0
        fi

        #execution block
        ricerca=($(find $path_iniziale -type f -name $argomento1)) #creating a vector with all the paths of the file
        if [[ ${#ricerca[@]} == 0 ]]; then #controlling if there are some paths
            echo "The file $argomento1 doesn't exist."
        else
            echo "Those are all the paths for the file: $argomento1"
            printf "%s \n" "${ricerca[@]}" #printing all the paths
        fi
        ;;

    2)  
        echo "You're creating a file named $argomento1 in $argomento2, if the file doesn't already exist."
    
        #control block
        if [[ $# != 3 ]]; then #controlling number of arguments
            echo "The script for the command $comando needs 3 arguments, retry please."
            exit 0
        fi 
        first2=$(echo $argomento2 | head -c 1) #first letter of second argument
        last2=$(echo -n $argomento2 | tail -c 1) #last letter of second argument
        if [[ $argomento1 != *.* ]]; then #controlling the pattern of the file
            echo "The file $argomento1 is written wrong, try using this pattern: file.ext."
            exit 0
        elif [[ $first2$last2 != [./]/ ]]; then #controlling the pattern of the directory
            echo "The directory $argomento2 is written wrong, try using relative (./path/) or absolute (/path/) path."
            exit 0
        fi

        #execution block
        if [[ -d $argomento2 ]]; then #controlling if the directory exists
            if [[ -f $argomento2$argomento1 ]]; then #controlling if the file exists
                echo "The file $argomento1 already exists in the directory $argomento2."
            else
                touch $argomento2$argomento1 #creating the file in the directory specified
                echo "The file $argomento1 has been created in the directory $argomento2."
            fi
        else
            mkdir $argomento2 #creating the directory specified
            echo "The directory $argomento2 has been created."
            touch $argomento2$argomento1 #creating the file in the directory specified
            echo "The file $argomento1 has been created in the directory $argomento2."
        fi
        ;;

    3)  
        echo "You're moving a file named $argomento1 from $argomento2 to $argomento3."

        #control block
        if [[ $# != 4 ]]; then #controlling number of arguments
            echo "The script for the command $comando needs 4 arguments, retry please."
            exit 0
        fi 
        first2=$(echo $argomento2 | head -c 1) #first letter of second argument
        last2=$(echo -n $argomento2 | tail -c 1) #last letter of second argument
        first3=$(echo $argomento3 | head -c 1) #first letter of third argument
        last3=$(echo -n $argomento3 | tail -c 1) #last letter of third argument
        if [[ $argomento1 != *.* ]]; then #controlling the pattern of the file
            echo "The file $argomento1 is written wrong, try using this pattern: file.ext."
            exit 0
        elif [[ $first2$last2 != [./]/ ]]; then #controlling the pattern of the source directory
            echo "The source directory $argomento2 is written wrong, try using relative (./path/) or absolute (/path/) path."
            exit 0
        elif [[ $first3$last3 != [./]/ ]]; then #controlling the pattern of the destination directory
            echo "The destination directory $argomento3 is written wrong, try using relative (./path/) or absolute (/path/) path."
            exit 0
        fi

        #execution block
        if [[ -f $argomento2$argomento1 ]]; then #controlling if the file exists
            if [[ $argomento2 ]]; then #controlling if the source directory exists
                if [[ -d $argomento3 ]]; then #controlling if the destination directory exists
                    mv $argomento2$argomento1 $argomento3 #transfering file from source to destination
                    echo "The file $argomento1 has been moved from source directory $argomento2 to destination directory $argomento3."
                else
                    while [[ $risposta != [Yn] ]]; do #check to see if the answer is been made right
                        echo "Do you want to create the destination directory $argomento3? (Y/n)" 
                        read risposta #reading the answer to execute it
                        if [[ $risposta == Y ]]; then #check if the answer is yes
                            mkdir $argomento3 #creating the directory wanted
                            echo "The destination directory $argomento3 has been created."
                            mv $argomento2$argomento1 $argomento3 #transfering file from source to destination
                            echo "The file $argomento1 has been moved from source directory $argomento2 to destination directory $argomento3."
                        elif [[ $risposta == n ]]; then #check if the answer is no
                            echo "You don't want to create the destination directory $argomento3."
                        else 
                            echo "This is not a possible answer retry please."
                        fi
                    done
                fi
            else
                echo "The source directory $argomento2 doesn't exist."
            fi
        else
            echo "The file $argomento1 doesn't exist."
        fi
        ;;

    4) 
        echo "You want to remove a file named $argomento1."

        #control block
        if [[ $# != 2 ]]; then #controlling number of arguments
            echo "The script for the command $comando needs 2 arguments, retry please."
            exit 0
        fi 
        if ! [[ $argomento1 =~ ^(\.\/|\/)?[^\.]+\.[^\/.]+$ ]] ; then #controlling the pattern of the file
            echo "The file $argomento1 is written wrong, try using this pattern: file.ext or /path/file.ext or ./path/file.ext."
            exit 0
        fi 

        #execution block
        if [[ -f $argomento1 ]]; then 
            rm $argomento1 #removing the file
            echo "The file $argomento1 has been removed."
        else
            echo "The file $argomento1 already doesn't exist."
        fi
        ;;

    5)  
        echo "You want to remove a directory named $argomento1."

        #control block
        if [[ $# != 2 ]]; then #controlling number of arguments
            echo "The script for the command $comando needs 2 arguments, retry please."
            exit 0
        fi 
        first1=$(echo $argomento1 | head -c 1) #first letter of first argument
        last1=$(echo -n $argomento1 | tail -c 1) #last letter of first argument
        if [[ $first1$last1 != [./]/ ]]; then #controlling the pattern of the directory
            echo "The directory $argomento1 is written wrong, try using relative (./path/) or absolute (/path/) path."
            exit 0
        fi

        #execution block
        if [[ -d $argomento1 ]]; then 
            rm -r $argomento1 #removing the directory
            echo "The directory $argomento1 has been removed."
        else
            echo "The directory $argomento1 already doesn't exist."
        fi
        ;;
    *)  
        echo "This command is not available, retry using one from 1 to 5." 
        ;;
esac