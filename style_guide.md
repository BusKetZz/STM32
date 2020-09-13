# Style Guide

- [What is it](#what-is-it)
- [Why to use that](#why-to-use-that)
- [Naming](#naming)
    - [Naming convention](#naming-convention)
    - [Source and header files names](#source-and-header-files-names)
    - [Variables names](#variables-names)
    - [Functions names](#functions-names)
    - [Structures names](#structures-names)
    - [Enums names](#enums-names)



## What is it

`Style guide` sets out rules regarding coding style.
In other words it describes:

* How to name variables, functions, structures, etc.?
* Do we use "snake_case" or "camelCase"?
* Where to place curly braces?
* What is the size of indentation?
* Do we use "spaces" or "tabs"?
* What is the structure of source and header files?
* And much much more...



## Why to use that

The answer is simple. Code is read by people, so write the code, which you want
to read. Research says, that if developers follows the rules (i.e. style)
throughout the whole project, code quality increases and amount of bugs
decreases. *SO... FOLLOW THE RULES... I mean STYLE!*.



## Naming 


### Naming convention

There is only one king: `snake_case`.


### Source and header files names

As mentioned above, `snake_case` is used throughout the whole project.
It means that source and header files (directories too) follow the same
convention.

**Example**: you want to write a module of temperature sensor.

* **Directories names**: sensors/source, sensors/include
* **Source file name**: temperature_sensor.c
* **Header file name**: temperature_sensor.h


### Variables names

`AUTOMATIC VARIABLES`

If the variable is automatic (i.e. local for given function) the name must be
as much descriptive as possible, but it doesn't have to be preceded by module
name.

**Example**: you want to define an automatic variable inside a public or
private function.

```c
void function(void)
{
    uint32_t systick_time = 0;
}
```


`PRIVATE GLOBAL VARIABLES`

If the variable is "private global" (i.e. it is accessible by all the functions
but only in the scope of given file) the name must be preceded by module name.
The reason for this choice is mostly the fact, that such variables stores
important information from the view point of given module.

**Example**: you want to define a private global variable inside a 
temperature_sensor.c file, which stores current temperature value.

```c
static float temperature_sensor_current_temperature = 0.0f;
```


`PUBLIC GLOBAL VARIABLES`

If the variable is "public global"... NO! THERE IS NO PLACE FOR SUCH BULLSHIT! 


### Functions names

Convention for functions names is very similar to the variables names.

`PRIVATE FUNCTIONS`

"Private" function means, that the function is accessible only in the given
file. Such a function is mostly the helper function, which improves code
organization.
Name of the private function must be as much descriptive as possible, but it
doesn't have to be preceded by module name.

**Example**: you want to define a private function inside temperature_sensor.h
file, which calculates current temperature.

```c
static float calculate_current_temperature(uin32_t adc_reading)
{
    /* ... */

    return current_temperature;
}
```


`PUBLIC FUNCTIONS`

"Public" function means, that the function is accessible from the other
modules. In other words function is global and can be used from anywhere.
Name of the public function must be preceded by the module name.

**Example**: you want to declare a public function prototype inside
temperature_sensor.h file, which returns current temperature.

```c
float temperature_sensor_get_current_temperature(void);
```


### Structures names

Convention for the structures is again very similar to variables and functions
names, but there is one small difference.

`PRIVATE STRUCTURES`

"Private" structure means, that the structure is declared inside given module
source file and you cannot define structure object outside this module.

Nevertheless most of the structures, whether private or public, store
important information from the view point of given module. Due to this fact,
most of the structures names should be preceded by module name.
If the structure is "really" the private one, it is not necessary.

What is more, each structure is declared using `typedef` keyword. There is no
specific reason of this choice, but it makes that formal arguments or structure
declarations are shorter. You don't need to use `typedef`, it is your choice.

**Example**: you want to declare a private structure inside
temperature_sensor.c file, which stores important data from the view point of
this module.

```c
typedef struct temperature_sensor_data {
    float previous_temperature;
    float current_temperature;
    float error_offset;
}temperature_sensor_data_t;
```

**Example**: you want to declare a private structure inside
temperature_sensor.c file, which is used only internally.

```c
typedef struct time_data {
    uint32_t systicks;
    uint32_t miliseconds;
    uint32_t seconds;
}time_data_t;
```


`PUBLIC STRUCTURES`

"Public" structure means, that the structure is declared inside given module
header file and you can define structure object outside this module.

**Example**: you want to declare a public structure inside
temperature_sensor.h file.

```c
typedef struct temperature_sensor_settings {
    temperature_sensor_device_mode_t device_mode;
    temperature_sensor_baudrate_t baudrate;
}temperature_sensor_settings_t;
```


### Enums names

Convention for enums is almost the same as for structures. The difference is
only in members names. In case of enums, members are written using uppercase.

`PRIVATE ENUMS`

"Private" enum means, that the enum is declared inside given module source
file and cannot be used outside this module.

**Example**: you want to declare private enum inside temperature_sensor.c file,
which is not related with important information regarding temperature sensor
module.

```c
typedef enum new_data_packet_ready {
    NEW_DATA_PACKET_READY_NO,
    NEW_DATA_PACKET_READY_YES
}new_data_packet_ready_t;
```


`PUBLIC ENUMS`

"Public" enum means, that the enum is declared inside given module header file
and can be used outside this module.

**Example**: you want to declare public enum inside temperature_sensor.h file,
which is related with important information regarding temperature sensor
module.

```c
typedef enum temperature_sensor_state {
    TEMPERATURE_SENSOR_STATE_ACTIVE,
    TEMPERATURE_SENSOR_STATE_CALIBRATION,
    TEMPERATURE_SENSOR_STATE_FATAL_FAILURE
}temperature_sensor_state_t;
```

