#/bin/bash

pattern_name=$1
log_name=$2

riscv_swimmer="../swimmer_riscv"
swimmer_opts="--init_pc 0x80000000 --debug --stop-host --max 50000"
# swimmer_opts="--init_pc 0x80000000"

echo "Executing " ${pattern_name} "..."

#========================
# check bit-mode
#========================
bit_mode=32
echo `basename ${pattern_name}` | grep -e 'rv64' > /dev/null
if [ $? -eq 0 ] ; then
    bit_mode=64
fi

echo ${riscv_swimmer} ${swimmer_opts} --arch rv${bit_mode}imafdc --binfile ${pattern_name} > ${log_name}
${riscv_swimmer} ${swimmer_opts} --arch rv${bit_mode}imafdc --binfile ${pattern_name} >> ${log_name} 2>&1
result=$?

if [ ${result} -eq 1 ]; then
	printf "%-30s Pass\n" `basename ${pattern_name}` >> result.txt
else
	printf "%-30s Fail\n" `basename ${pattern_name}` >> result.txt
fi
