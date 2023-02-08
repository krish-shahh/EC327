def get_register_code(register):
    return int(register[1:])

def get_instruction_code(instruction):
    if instruction == "halt":
        return 0x0000
    elif instruction == "inc":
        return 0xC000
    elif instruction == "jmp":
        return 0xC800
    elif instruction == "jne":
        return 0xD000
    elif instruction == "je":
        return 0xD800
    elif instruction == "add":
        return 0x1000
    elif instruction == "sub":
        return 0x2000
    elif instruction == "xor":
        return 0x3000
    elif instruction == "cmp":
        return 0x4000
    elif instruction.startswith("mov Rn, num"):
        return 0x5000
    elif instruction.startswith("mov Rn, Rm"):
        return 0x6000
    elif instruction.startswith("mov [Rn], Rm"):
        return 0x7000
    elif instruction.startswith("mov Rn, [Rm]"):
        return 0x8000
    else:
        return None

def assemble(instruction):
    instruction_code = get_instruction_code(instruction)
    if instruction_code is None:
        return None
    
    if instruction == "halt":
        return hex(instruction_code)
    elif instruction in ["inc", "jmp", "jne", "je"]:
        return hex(instruction_code | get_register_code(instruction.split()[1]))
    else:
        operands = instruction.split()[1:]
        if instruction.startswith("mov Rn, num"):
            return hex(instruction_code | (get_register_code(operands[0]) << 8) | int(operands[2]))
        elif instruction.startswith("mov Rn, Rm"):
            return hex(instruction_code | (get_register_code(operands[0]) << 8) | (get_register_code(operands[2]) << 4))
        elif instruction.startswith("mov [Rn], Rm"):
            return hex(instruction_code | (get_register_code(operands[1]) << 8) | (get_register_code(operands[3][:-1]) << 4))
        elif instruction.startswith("mov Rn, [Rm]"):
            return hex(instruction_code | (get_register_code(operands[0]) << 8) | (get_register_code(operands[2][:-1]) << 4))

while True:
    instruction = input("Enter an instruction (or type 'exit' to quit): ")
    if instruction == "exit":
        break
    
    result = assemble(instruction)
    if result is None:
        print("Error: invalid instruction")
    else:
        print("Hexadecimal code:", result)
