cat /etc/passwd | sed 's/:.*//' | sed -n '3,16p' | awk '{if(NR%2==0) print $0;}' | rev | awk '{a[NR]=$0} END {for(i=NR;i>10;i--) print a[i]}' | tr '\n' ' ' | sed 's/ /, /g'| sed 's/, $/./' 
