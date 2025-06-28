bool push(char* stack, char letter, int top) {
  if (top < 0) return false;

  stack[top] = letter;
  printf("%c\n", stack[top]);
  return true;
}

// char pop(char* stack, int top) {}

char* longestDiverseString(int a, int b, int c) {
  char* s = malloc(sizeof(char) * ( a + b + c) );
  int map[3] = {a, b, c};

 
  for (int i = 0; i < (a + b + c) - 1; i++) {
    if (map[0] > 0) {
      push(s, 'a', i);
      if ( i > 2 && strcmp( &s[i-2], "aaa") ) {
       // pop(s, i);

      } else {
        map[0]--;
        continue; 
      }
    }
    if (map[1] > 0) {
      push(s, 'b', i);
      if (i > 2 && strcmp( &s[i-2], "bbb") ) {
      //  pop(s, i);
      } else {
        map[1]--;
        continue;
      }
    }
    if (map[2] > 0) {
      push(s, 'c', i);
      if (i > 2 && strcmp( &s[i-2], "ccc")) {
     //   pop(s, i);
      } else {
        map[2]--;
        continue;
      }
    }
  }

  return s;
}