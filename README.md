# Vektoriai
Realizuota vektorių klasė

### Pushback() test'inimas 

|                 |  10.000 | 100.000 | 1.000.000 |
| :-------------- |:------- | :------ | :-------- | 
| std::vector     |   1ms   |   3ms   |    37ms   |
| Mano Vector     |   1ms   |   18ms  |   2166ms  |


Užpildant vektorius 1.000.000 kartų, capacity() == size():
* std::vector - 20 kartų
* Mano Vector - 1000 kartų

### Studentų test'inimas su 100.000 studentų

|                 |  Bendras laikas |
| :-------------- |:--------------- | 
| std::vector     |       671ms     |
| Mano Vector     |       1662ms    |
