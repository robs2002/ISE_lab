#!/bin/bash

shopt -s extglob #usato per poter inserire pattern come !(arg1|arg2)

vector_d=($(find . -type d -name gr[0-9][0-9]_lab01 | sort)) #cerco le cartelle con in formato giusto e le ordino
lenght_v=${#vector_d[*]} #numero di cartelle trovate 
let "l_v = $lenght_v -1"

NEWFILE=report.txt #nome del file di report che creo
if [[ -f $NEWFILE ]] #controllo se esiste file
    then
        rm $NEWFILE #se esiste, cancello il file
fi
touch $NEWFILE #creo il file di report

path=$(pwd) #percorso dove eseguo questo file

for i in $(seq 0 1 $l_v) #mi sposto nelle cartelle trovate
do
let "numg = $i +1" #numero del gruppo della cartella in esame
printf "gr0$numg " >>$NEWFILE 

    if [[ -d ${vector_d[i]}/es02/ ]] #controllo se esiste la cartella es02/
        then

        if [[ -f ${vector_d[i]}/es02/es02.sh ]] #controllo se esiste il file es02/es02.sh
            then

            if [[ -f ${vector_d[i]}/es02/host.txt ]] #controllo se esite il file es02/host.txt
            then

                if [[ $(diff "host.txt" "${vector_d[i]}/es02/host.txt") ]] #se ci sono differenze tra il mio host.txt e il file es02/host.txt 
                then
                    cp "host.txt" "${vector_d[i]}/es02" #lo sovrascrivo uguale al mio
                fi

            else
                touch "${vector_d[i]}/es02/host.txt" #se non esiste lo creo uguale al mio
                cp "host.txt" "${vector_d[i]}/es02"
            fi

            cd ${vector_d[i]}/es02 #vado nella cartella es02 in esame
            
            rm !("es02.sh"|"host.txt") #rimuovo i file che non sono es02.txt e host.txt

            if ! [[ -x ${vector_d[i]}/es02/es02.sh ]]  #se es02.sh non è eseguibile
            then
                chmod +x ./es02.sh #lo rendo eseguibile
            fi
            
            ./es02.sh #eseguo il file

            cd $path

            if [[ -f ${vector_d[i]}/es02/hostRenamed.txt ]] #controllo se esiste es02/hostRenamed.txt
            then

            diff_v=$(diff "hostRenamed.txt" "${vector_d[i]}/es02/hostRenamed.txt" | grep "<" | wc -l ) #guardo le differenze tra hostRenamed.txt giusto e quello nella cartella es02 e vedo le righe che sono diverse
            let "corr = 6 - $diff_v" #righe corrette
                if [[ $diff_v == "0" ]] #se non ci sono differenze 
                then
                    printf "OK.\n" >>$NEWFILE  #i file matchano             
                else
                    let "PERCENTUALE = 100 * $corr / 6" #se non matchano calcolo la percentuale righe giuste 
                    printf "KO Unmatched output (%d%% correct). \n" "$PERCENTUALE" >>$NEWFILE
                fi

           else

               printf "KO no es02/hostRenamed.txt was generated. \n" >>$NEWFILE 
           fi

        else

           printf "KO Missing file es02/es02.sh.\n" >>$NEWFILE

        fi

    else
        printf "KO Missing directory es02/. \n" >>$NEWFILE

    fi

done


