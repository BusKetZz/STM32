## Linker scripts
* Linker script is a text file which explains how different sections of the
  object files should be merged to create an output file.
* Linker and locator combination assigns unique absolute addresses to different
  sections of the output file by referring to address information mentioned in
  the linker script.
* Linker script also includes the code and data memory addresses and size
  information.
* Linker scripts are written using the GNU linker command language.
* GNU linker script has the file extesnion of .ld.
* One must supply linker script at the linking phase to the linker using -T
  option.

### ENTRY command
* This command is used to set the "**Entry point address**" information in the
  header of final elf file generated.
* In the case of STM32 project, "reset_handler" is the entry point into the
  application - the first piece of code that executes right after the processor
  reset.
* The debugger uses this information to locate the first function to execute.
* Not a mandatory command to use, but required when one debugs the elf file
  using the debugger (GDB).
* Syntax: ENTRY(symbol_name), eg. ENTRY(reset_handler).

### MEMORY command
* This command allows one to describe the different memories present in the
  target and their start address and size information.
* The linker uses information mentioned in this command to assign addresses to
  merged sections.
* The information given under this command also helps the linker to calculate
  total code and data memory consumed so fat and throw an error message if
  data, code, heap or stack areas cannot fit into available size.
* By using memory command, one can fine-tune various memories available in
  target and allow different sections to occupy different memory areas.
* Typically one linker script has one memory command.
* Syntax: 
  MEMORY
  {
	  name(attribute) : ORIGIN = origin, LENGTH = length
  }

### SECTIONS command
* This command is used to create different output sections in the final elf
  executable generated.
* Important command by which one can instruct the linker how to merge the input
  sections to yield an output section.
* This command also controls the order in which different output sections
  appear in the elf file generated.
* By using this command, one also mentions the placement of a section in a
  memory region. For example, one instructs the linker to place the .text
  section in the FLASH memory region, which is described by the MEMORY command.

### Location counter '.'
* This is a special linker symbol denoted by a dot ','.
* This symbol is called "location counter" since linker automatically updates
  this symbol with location (address) information.
* One can use this symbol inside the linker script to track and define
  boundaries of various sections.
* One can also set location counter to any specific value while writing linker
  script.
* Location counter should appear only inside the SECTIONS command.
* The location counter is incremented by the size of the output section.

