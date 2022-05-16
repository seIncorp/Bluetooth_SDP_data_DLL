# Data elements
ATTR_ID* attr_id
VV VALUE ([DETAILS](VALUE.md))

# Functions
void printATTR_ELEMENT(IOCTL_S::DEFAULT_DATA dd)
void printVALUE_ELEMENT(T v, IOCTL_S::DEFAULT_DATA dd)
void print(T v, IOCTL_S::DEFAULT_DATA dd)


# Substrucutres
## ATTR_ID
### Data elements
* ATTRIBUTE_ID_ELEMENT* element ([DETAILS](ATTRIBUTE_ID_ELEMENT.md))
int size_bytes
int additional_bits_flag
int additional_bits_for_size
BYTE* value




