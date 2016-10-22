awk 'NR==FNR{a[i++]=$0}NR>FNR{print a[j++]  $2}' employee.txt bonus.txt
