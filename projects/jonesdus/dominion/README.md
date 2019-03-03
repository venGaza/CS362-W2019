run make all #To compile the dominion code
run ./playdom 30 # to run playdom code

#Assignment 4 - Random Generator Card Tests

#Compile all cards and files at same time (adventurer, smithy, embargo)
make randomTestAll 

#Compile adventurer only
make testAdventurer

#Compile smithy only
make testSmithy

#Compile embargo only
make testEmbargo

#Clean all files (for any above scenario)
make clean