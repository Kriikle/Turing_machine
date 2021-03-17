# Turing_machine
##To run use Source.cpp 

###Output forms in file out.txt

###Rules are in file in.txt

###Descriotion of in.txt
_111_111___________________ - input line

1_ - alfabet

...

* > q9_->q41R 
- if 9q and symbol _ come 4q,Rigth move on line changing symbol _ to 1

* > q:1->q:1L 
- if 10q and symbol 1 come 10q,Left move on line changing symbol 1 to 1

* > q:_->q;_L
 - if 10q and symbol 1 come 11q,Left move on line changing symbol _ to _

* > q;1->q<1L 
- if 11q and symbol 1 come 12q,Left move on line changing symbol 1 to 1

...

*** Q description
  First q is 1 
  Finish(stop) q is 0
    * ACII : - is ACII 0 + 10
    * ACII ; - is ACII 0 + 11
    * ACII < - is ACII 0 + 12
    *q max is acii max - 0
