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
bool fact();
bool term();
bool expr();
bool add_op();
bool mul_op();

bool P_OPEN(){
  return match('(');
}
bool P_CLOSE(){
  return match(')');
}

bool expr_1(){
  if (!term()) return false;
  if (!add_op()) return false;
  if (!expr()) return false;
  return true;
}

bool expr_2(){
  if (!term()) return false;
  return true;
}

bool expr() {
  int o_pos = pos_cur();
  if (expr_1()) return true;
  pos_set(o_pos);
  if (expr_2()) return true;
  pos_set(o_pos);
  return false;
}

bool term_1() {
  if (!fact()) return false;
  if (!mul_op()) return false;
  if (!term()) return false;
  return true;
}

bool term_2() {
  return fact();
}

bool term() {
  int o_pos = pos_cur();
  if (term_1()) return true;
  pos_set(o_pos);
  if (term_2()) return true;
  pos_set(o_pos);
  return false;
}

bool fact_1() {
  if (!P_OPEN()) return false;
  if (!expr()) return false;
  if (!P_CLOSE()) return false;
  return true;
}

bool fact_2() {
  return digits();
}

bool fact() {
  int o_pos = pos_cur();
  if (fact_1()) return true;
  pos_set(o_pos);
  if (fact_2()) return true;
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
  assert(expr());
  assert(pos_eof());
}

