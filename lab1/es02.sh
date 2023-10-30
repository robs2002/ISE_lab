#!/bin/bash

FILE="host.txt"
NEWFILE="hostRenamed.txt"
count=1

if [[ ! -f $(pwd)/$FILE ]]; then
   printf "File $FILE doesn't exists.\n"
   exit 1
fi

if [[ -f $(pwd)/$NEWFILE ]]; then
 rm $NEWFILE
 touch $NEWFILE
 echo "File already named $NEWFILE found and removed."
fi

cutnome=($(cut -d "." -f 5-6 $FILE | cut -d " " -f 1))

while read LINE
   do 
   printf "192.168.1.%d host%d.${cutnome[((count-1))]} host%d\n" "$(( count+30 ))" "$count" "$count" >>$NEWFILE
   ((count++))
   
done < $FILE

echo "File modified."


   #printf "192.168.1.%d " "$(( count+30 ))" >>$NEWFILE 
   #printf "host%d." "$count" >>$NEWFILE
   #printf "${cutnome[((count-1))]}" >>$NEWFILE
   #printf " host%d\n" "$count" >>$NEWFILE
   