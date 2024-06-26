/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
   "0", "ra", "tp", "sp", "a0", "a1", "a2", "a3",
  "a4", "a5", "a6", "a7", "t0", "t1", "t2", "t3",
  "t4", "t5", "t6", "t7", "t8", "rs", "fp", "s0",
  "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8",
};
const int reg_len = ARRLEN(regs);

void isa_reg_display() {
  printf("pc:" FMT_PADDR "\n",cpu.pc);
  for(int i=0;i<reg_len;i++){
    if(i%4==0 && i!=0)printf("\n");
    printf("%3s:" FMT_PADDR " \t\t",regs[i], gpr(i));
  }
  printf("\n");

}

word_t isa_reg_str2val(const char *s, bool *success) {
  *success = true;
  for(int i = 0;i<reg_len;i++){
    if(strcmp(s,regs[i]) == 0){
      return gpr(i);
    }
  }
  if(strstr(s, "pc") != NULL){
    return cpu.pc;
  }
  *success = false;
  return 0;
}

