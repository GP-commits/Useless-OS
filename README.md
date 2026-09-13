<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />


  # Useless OS 🎯

  ## Basic Details

  ### Team Name: Aura Farmer

  ### Team Members

  - Team Lead: Sivadarsh P Dinesh - School of Engineering, CUSAT
  - Member 2: [Name] - [College]
  - Member 3: [Name] - [College]

  ### Project Description

  Useless OS is a tiny bootable x86_64 operating system that proudly accomplishes almost nothing. It features a
  pixel-based interface, a deliberately unhelpful “AI,” an About page, and a Dino game—all packed into a bootable
  ISO.

  ### The Problem (that doesn't exist)

  Modern operating systems are far too useful. They help people work, communicate, create, and remain productive—
  which is clearly unacceptable.

  ### The Solution (that nobody asked for)

  Useless OS removes all those distracting productivity features. It boots into a beautifully minimal menu, answers
  every question with “I DON'T KNOW,” and lets a dinosaur run until it inevitably dies. Finally, an operating system
  that respects your desire to achieve absolutely nothing.

  ## Technical Details

  ### Technologies/Components Used

  For Software:

  - Languages: C and x86 inline assembly
  - Frameworks: None — freestanding bare-metal kernel
  - Libraries/Protocols: Limine Boot Protocol and freestanding C headers
  - Tools: GNU Make, GCC/Clang, GNU Linker/LLD, QEMU, Limine Bootloader, xorriso and Git
  - Architecture: x86_64
  - Input: PS/2 keyboard input using hardware I/O ports
  - Graphics: Direct framebuffer rendering with a custom pixel font

  For Hardware:

  - Main components: Not applicable — Useless OS is a software-only project
  - Specifications: An x86_64 computer or virtual machine capable of booting an ISO
  - Tools required: No physical hardware tools required

  ### Implementation

  For Software:

  # Installation

  ```bash
  git clone https://github.com/GP-commits/Useless-OS.git
  cd Useless-OS
  make TOOLCHAIN=llvm
  ```

  # Run

  ```bash
  make TOOLCHAIN=llvm run
  ```

  ### Project Documentation

  For Software:

  # Screenshots (Add at least 3)

<img width="1918" height="1020" alt="image" src="https://github.com/user-attachments/assets/8828a4d7-b48d-4356-8c11-db2f83e8b7b6" />
  *Home screen of the Operating System*

  <img width="1920" height="1025" alt="image" src="https://github.com/user-attachments/assets/c5ec77bb-b282-465a-a115-5337fad7dbaa" />
  *Useless ai*

<img width="1920" height="1023" alt="image" src="https://github.com/user-attachments/assets/b96048d8-edb0-49da-863c-8686670c072f" />
  *About section of the operating system*

  # Diagrams

  <img width="1340" height="3243" alt="useless-os-workflow" src="https://github.com/user-attachments/assets/ffc6d839-66e0-4e4b-819c-d7dd959cdc2c" /><br>
  *Workflow showing the boot process, main menu, Useless AI, About section, and Dino Game.*

  For Hardware:

  # Schematic & Circuit

  ![Circuit](Add your circuit diagram here)
  *Not applicable — this is a software-only project with no external circuit.*

  ![Schematic](Add your schematic diagram here)
  *Not applicable — Useless OS runs on an x86_64 computer or virtual machine.*

  # Build Photos

  ![Components](Add photo of your components here)
  *No physical components were used; the project consists of source code and a bootable ISO.*

  <img width="883" height="1002" alt="image" src="https://github.com/user-attachments/assets/e4313d11-f79f-4811-806c-fca8c637ddff" />
  *The kernel is compiled and linked, then packaged with the Limine bootloader into a bootable ISO.*

  <img width="1920" height="1080" alt="20260913_152839" src="https://github.com/user-attachments/assets/7fc6dd6d-aad6-4df6-a40e-561543625550" />
  *The final product is Useless OS running from its bootable ISO in QEMU or on compatible hardware.*

  ### Project Demo

  # Video

 [ [demo video link](https://drive.google.com/file/d/1CdCQ8ZUPTlyNnDEQZ3xIPqix0O1AJe-7/view?usp=sharing)
  *The video demonstrates Useless OS booting, the main menu, Useless AI, the About page, and the Dino Game.*

  # Additional Demos

  [Add any extra demo materials/links]

  ## Team Contributions

  - Sivadarsh: Entire Project
  - [Name 2]: [Specific contributions]
  - [Name 3]: [Specific contributions]

  ---

 Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)
