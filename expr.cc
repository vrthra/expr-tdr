#include<stdio.h> 
#include<string.h> 
#include<assert.h> 
char* my_input = 0;
int input_len = -1;
int cur_position = 0;

int pos_cur() {
  return cur_position;
}

void pos_set(int i) {
  cur_position = i;
}

bool pos_eof() {
  return pos_cur() == input_len;
}

int next_token() {
  int i = pos_cur();
  if ((i+1) > input_len){
    return -1;
  }
  pos_set(i+1);
  return my_input[i];
}

bool match(int t) {
  return next_token() == t;
}

bool digit();
bool digits();
bool term();
bool expr();
bool product();
bool pstar();
bool sstar();
bool sum();
bool value();
bool add_op();
bool mul_op();

bool P_OPEN(){
  return match('(');
}
bool P_CLOSE(){
  return match(')');
}

bool expr_1(){/**/
  if (!sum()) return false;
  return true;
}

bool expr() {/**/
  if (expr_1()) return true;
  return false;
}


bool sum_1(){/**/
  if (!product()) return false;
  if (!sstar()) return false;
  return true;
}

bool sum() {/**/
  if (sum_1()) return true;
  return false;
}


bool sstar_1() {/**/
  if (!add_op()) return false;
  if (!product()) return false;
  if (!sstar()) return false;
  return true;
}

bool sstar_2() {/**/
  /*epsilon*/
  return true;
}

bool sstar() {/**/
  int o_pos = pos_cur();
  if (sstar_1()) return true;
  pos_set(o_pos);
  if (sstar_2()) return true;
  pos_set(o_pos);
  return false;
}

bool pstar_1() {/**/
  if (!mul_op()) return false;
  if (!value()) return false;
  if (!pstar()) return false;
  return true;
}

bool pstar_2() {/**/
  /*epsilon*/
  return true;
}

bool pstar() {/**/
  int o_pos = pos_cur();
  if (pstar_1()) return true;
  pos_set(o_pos);
  if (pstar_2()) return true;
  pos_set(o_pos);
  return false;
}

bool product_1() {/**/
  if (!value()) return false;
  if (!pstar()) return false;
  return true;
}

bool product() {/**/
  if (product_1()) return true;
  return false;
}

bool value_1() {/**/
  if (!digits()) return false;
  return true;
}

bool value_2() {/**/
  if (!P_OPEN()) return false;
  if (!expr()) return false;
  if (!P_CLOSE()) return false;
  return true;
}

bool value() {/**/
  int o_pos = pos_cur();
  if (value_1()) return true;
  pos_set(o_pos);
  if (value_2()) return true;
  pos_set(o_pos);
  return false;
}

bool digits_1() {
  if (!digit()) return false;
  if (!digits()) return false;
  return true;
}

bool digits_2() {
  return digit();
}

bool digits() {
  int o_pos = pos_cur();
  if (digits_1()) return true;
  pos_set(o_pos);
  if (digits_2()) return true;
  pos_set(o_pos);
  return false;
}

bool digit() {
  int o_pos = pos_cur();
  if (match('1')) return true;
  pos_set(o_pos);
  if (match('2')) return true;
  pos_set(o_pos);
  if (match('3')) return true;
  pos_set(o_pos);
  if (match('4')) return true;
  pos_set(o_pos);
  if (match('5')) return true;
  pos_set(o_pos);
  if (match('6')) return true;
  pos_set(o_pos);
  if (match('7')) return true;
  pos_set(o_pos);
  if (match('8')) return true;
  pos_set(o_pos);
  if (match('9')) return true;
  pos_set(o_pos);
  if (match('0')) return true;
  pos_set(o_pos);
  return false;
}

bool add_op() {
  int o_pos = pos_cur();
  if (match('+')) return true;
  pos_set(o_pos);
  if (match('-')) return true;
  pos_set(o_pos);
  return false;
}
bool mul_op() {
  int o_pos = pos_cur();
  if (match('*')) return true;
  pos_set(o_pos);
  if (match('/')) return true;
  pos_set(o_pos);
  return false;
}


int main(int argc, char** argv){
  my_input = argv[1];
  input_len = strlen(my_input);
  int val = expr();
  /*assert(val);
  assert(pos_eof());*/
  if(!val) return -1;
  if(!pos_eof()) return -1;
}

