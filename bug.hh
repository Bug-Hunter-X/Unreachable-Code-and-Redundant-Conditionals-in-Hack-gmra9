function foo(x: int): int {  return x + 1; } function bar(x: int): int {  return foo(x) * 2; } function baz(x: int): int {  return bar(x) + 1; }  //This is fine, the function works well.  However, if we have a function like this one: function wrongFoo(x: int): int {  return x + 1;  if (x == 0) {  return 0; //This code can never be reached } }  The compiler will not complain about this, even though the `return 0;` statement is unreachable. This is because Hack's type checker does not perform full control flow analysis to detect unreachable code.  This can lead to subtle bugs where the code compiles without errors, but the logic is incorrect.  Another example: function example(x: string): int {  if (x == "hello") {  return 1;  } else if (x == "world") {  return 2;  }  return 3; }  This code is fine, but suppose you add another conditional like: function example2(x: string): int {  if (x == "hello") {  return 1;  } else if (x == "world") {  return 2;  } else if (x == "hello") {  return 4; //This can never be reached due to the previous condition  }  return 3; }  The code compiles and runs, but it has redundant and potentially misleading conditionals that won't affect the result. The compiler doesn't warn about these potential issues. 