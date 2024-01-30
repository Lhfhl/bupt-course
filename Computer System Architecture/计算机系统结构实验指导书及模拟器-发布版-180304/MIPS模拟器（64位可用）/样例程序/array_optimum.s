.text
main: 
ADDIU $r1,$r0,array1  # 第一个数组的段地址
ADDIU $r2,$r0,array2  # 第二个数组的段地址
ADDIU $r3,$r0,10  # 向量长度设置为10
ADDIU $r4,$r0,0  # 用r4保存点积结果
loop: 
LW $r5,0($r1) 
LW $r6,0($r2) 
ADDI $r1,$r1,4  # 获取下一个数据
MUL $r7,$r5,$r6  # 乘法运算——优化位置
ADDI $r2,$r2,4  # 获取下一个数据
ADDI $r3,$r3,-1  # 实现递减
ADD $r4,$r4,$r7  # 用r4 存放点积结果——优化位置
BGTZ $r3,loop  # 进行循环判断
TEQ $r0,$r0
.data 
array1: .word 1,2,3,4,5,6,7,8,9 
array2: .word 1,2,3,4,5,6,7,8,9