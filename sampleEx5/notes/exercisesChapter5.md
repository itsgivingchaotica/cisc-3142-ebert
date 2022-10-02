# **Exercises from Chapter 5**

## **Exercise 5.1**
< What is a null statement? When might you use a null statement?
An empty statement `;` We can use a null statement when it is required to have a statement but it is not needed for the logic of the program to check out. For example, if we want to read in values until we find the value we need in a while loop, a null statement can be used to exit the loop.

## **Exercise 5.2**
< What is a block? When might you use a block?
A compound statement surrounded by a pair of curly braces `{}` ; a scope. Used when a single statement is required but the program needs more than one. For example, in a while loop we may need to not only add a value to a sum but also incremenet the value to continue adding values to the sum until the while loop is broken.

## **Exercise 5.4**
< Explain each of the following examples, and correct any problems you detect.
(a) `while (string::iterator iter != s.end() { / * ... * / }` is invalid because iter does not point to anything, to fix this we may declare `string::iterator iter = s.begin(); then use the while statement accordingly `while (iter != s.end() { / * ... * / }`
(b) `while (bool status = find(word)) { / * ... * / } if (!status) { / * ... * / }` is invalid because `status` was declared only  in the while statment and can only be used within the scope of that block. To use in the if statement we would need to declare `bool status;` prior to the `while` loop and `if` statement. `bool status; while ((status = find(word))) { / * ... * / } if (!status) { / * ... * / }`

## **Exercise 5.7**
< Correct the errors in each of the following code fragments:
(a) 
```
if (ival1 != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
```

Rewrite:
```
if (ival1 != ival2)
    ival1 = ival2; //adding missing semicolon
else
    ival1 = ival2 = 0;
```
    
(b)
```
if (ival < minval)
    minval = ival;
    occurs = 1;
```

Rewrite: 
```
if (ival < minval)
{ //use block to add more than one line of code for if statement
    minval = ival; 
    occurs = 1;
}
```

(c) 
```
if (int ival = get_value())
    cout << "ival = " << ival << endl;
```
Need to add the following `else` to make an if-else statement
```
else if (!ival)
    cout << "ival = 0" << endl;
```

(d)
```
if (ival = 0)
    ival = get_value(); 
```

if statement uses assignment not equals, should be
```
if (ival == 0) // if ival equals 0
    ival = get_value();
```

## **Exercise 5.8**
< What is a "dangling `else`"? How are `else` clauses resolved in C++?
When there is more `if` branches than `else` branches it results in dangling `else`, we can resolve this in C++ by making sure to specify that each `else` matches with the previous unmatched `if` closest to it.

## **Exercise 5.13**
< Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

(a)
```
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch){
    case 'a' : aCnt++;
    case 'b' : eCnt++;
    default: iouCnt++;
}
```
Missing `break;` for each `case`

```
switch (ch){
    case 'a' : aCnt++; break;
    case 'b' : eCnt++; break;
    default: iouCnt++; break;
} 
```

(b)
```
unsigned index = some_value();
switch (index){
    case 1:
        int ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}
```
We need to declare `int ix` before the `case`s in order to use `ix = ivec.size() -1;` under the `default` case.

(c)
```
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit){
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```
`case` cannot work that way. Must be `case 1 : case 3 : case 5 : case 7 : case 9 :` etc.

(d)
```
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt){
    case ival :
        bufsize = ival * sizeof(int);
        break;
    case jval :
        bufsize = jval * sizeof(int);
        break;
    case kval :
        bufsize = kval * sizeof(int);
        break;
}
```
We cannot use a nonconst case label. Use `const unsigned ival = 512, jval = 1024, kval = 4096;` 

