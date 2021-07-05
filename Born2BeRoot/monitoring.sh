#!/bin/bash

printf "Architecture : "
uname -srvm

printf "Nombre de processeurs : "
nproc --all

printf "Nombre de processeurs virtuels : "
cat /proc/cpuinfo | grep processor | wc -l

printf "Memoire utilisee : "
free -m | grep Mem | awk '{printf"%d/%dMb (%.2f%%)\n", $3, $2, $3 / $2 * 100}'

printf "Espace de stockage utilise : "
df -BMa | grep /dev/mapper/ | awk '{sum1+=$3;sum2+=$4}END{printf "%d/%dGb (%.2f%%)\n", sum1, sum2/1000, sum1/sum2 * 100}' | tr -d '\n'
printf "\n"

printf "Charge CPU : "
mpstat | grep all | awk '{printf "%.2f%%\n", 100 - $13}'

printf "Dernier Boot : "
who -b | sed 's/ system boot// g'

printf "LVM utilisee : "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "Connexions TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " established \n"

printf "User Log : "
who | wc -l

printf "Sudo : "
grep 'sudo:' /var/log/auth.log | grep 'COMMAND=' | wc -l | tr -d '\n'
printf " cmd\n"
