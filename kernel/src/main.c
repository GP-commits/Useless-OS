#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>

// Set the base revision to 6, this is recommended as this is the latest
// base revision described by the Limine boot protocol specification.
// See specification for further info.

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent, _and_ they should be accessed at least
// once or marked as used with the "used" attribute as done here.

__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

// Finally, define the start and end markers for the Limine requests.
// These can also be moved anywhere, to any .c file, as seen fit.

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] = LIMINE_REQUESTS_END_MARKER;

// Halt and catch fire function.
static void hcf(void) {
    for (;;) {
        asm ("hlt");
    }
}


	static void  put_pixel(
		struct limine_framebuffer *fb,
		size_t x,
		size_t y,
		uint32_t color
		){
		volatile uint32_t *pixels = fb->address;
		pixels[y *(fb -> pitch /4) + x] = color;
		}

		static const uint8_t *get_letter(char c) {

			static const uint8_t font[36][7] = {

				// A
				{0b01110,0b10001,0b10001,0b11111,0b10001,0b10001,0b10001},

				// B
				{0b11110,0b10001,0b10001,0b11110,0b10001,0b10001,0b11110},

				// C
				{0b01111,0b10000,0b10000,0b10000,0b10000,0b10000,0b01111},

				// D
				{0b11110,0b10001,0b10001,0b10001,0b10001,0b10001,0b11110},

				// E
				{0b11111,0b10000,0b10000,0b11110,0b10000,0b10000,0b11111},

				// F
				{0b11111,0b10000,0b10000,0b11110,0b10000,0b10000,0b10000},

				// G
				{0b01111,0b10000,0b10000,0b10111,0b10001,0b10001,0b01111},

				// H
				{0b10001,0b10001,0b10001,0b11111,0b10001,0b10001,0b10001},

				// I
				{0b11111,0b00100,0b00100,0b00100,0b00100,0b00100,0b11111},

				// J
				{0b00111,0b00010,0b00010,0b00010,0b10010,0b10010,0b01100},

				// K
				{0b10001,0b10010,0b10100,0b11000,0b10100,0b10010,0b10001},

				// L
				{0b10000,0b10000,0b10000,0b10000,0b10000,0b10000,0b11111},

				// M
				{0b10001,0b11011,0b10101,0b10101,0b10001,0b10001,0b10001},

				// N
				{0b10001,0b11001,0b10101,0b10011,0b10001,0b10001,0b10001},

				// O
				{0b01110,0b10001,0b10001,0b10001,0b10001,0b10001,0b01110},

				// P
				{0b11110,0b10001,0b10001,0b11110,0b10000,0b10000,0b10000},

				// Q
				{0b01110,0b10001,0b10001,0b10001,0b10101,0b10010,0b01101},

				// R
				{0b11110,0b10001,0b10001,0b11110,0b10100,0b10010,0b10001},

				// S
				{0b01111,0b10000,0b10000,0b01110,0b00001,0b00001,0b11110},

				// T
				{0b11111,0b00100,0b00100,0b00100,0b00100,0b00100,0b00100},

				// U
				{0b10001,0b10001,0b10001,0b10001,0b10001,0b10001,0b01110},

				// V
				{0b10001,0b10001,0b10001,0b10001,0b10001,0b01010,0b00100},

				// W
				{0b10001,0b10001,0b10001,0b10101,0b10101,0b10101,0b01010},

				// X
				{0b10001,0b10001,0b01010,0b00100,0b01010,0b10001,0b10001},

				// Y
				{0b10001,0b10001,0b01010,0b00100,0b00100,0b00100,0b00100},

				// Z
				{0b11111,0b00001,0b00010,0b00100,0b01000,0b10000,0b11111},

				// 0
				{0b01110,0b10001,0b10011,0b10101,0b11001,0b10001,0b01110},

				// 1
				{0b00100,0b01100,0b00100,0b00100,0b00100,0b00100,0b01110},

				// 2
				{0b01110,0b10001,0b00001,0b00010,0b00100,0b01000,0b11111},

				// 3
				{0b11110,0b00001,0b00001,0b01110,0b00001,0b00001,0b11110},

				// 4
				{0b00010,0b00110,0b01010,0b10010,0b11111,0b00010,0b00010},

				// 5
				{0b11111,0b10000,0b10000,0b11110,0b00001,0b00001,0b11110},

				// 6
				{0b01110,0b10000,0b10000,0b11110,0b10001,0b10001,0b01110},

				// 7
				{0b11111,0b00001,0b00010,0b00100,0b01000,0b01000,0b01000},

				// 8
				{0b01110,0b10001,0b10001,0b01110,0b10001,0b10001,0b01110},

				// 9
				{0b01110,0b10001,0b10001,0b01111,0b00001,0b00001,0b01110}
			};


			// A-Z
			if (c >= 'A' && c <= 'Z') {
				return font[c - 'A'];
			}

			// 0-9
			if (c >= '0' && c <= '9') {
				return font[26 + (c - '0')];
			}

			return 0;
		}

static void draw_char(
	struct limine_framebuffer *fb,
	char c,
	size_t start_x,
	size_t start_y,
	size_t scale,
	uint32_t color
) {
	const uint8_t *letter = get_letter(c);

	if (letter == 0) {
		return;
	}

	for (size_t row = 0; row < 7; row++) {
		for (size_t col = 0; col < 5; col++) {

			if (letter[row] & (1 << (4 - col))) {

				for (size_t sy = 0; sy < scale; sy++) {
					for (size_t sx = 0; sx < scale; sx++) {

						put_pixel(
							fb,
				start_x + col * scale + sx,
				start_y + row * scale + sy,
				color
						);
					}
				}
			}
		}
	}
}






static void draw_ascii_sprite(
    struct limine_framebuffer *fb,
    const char **sprite,
    size_t rows,
    size_t x,
    size_t y,
    size_t scale,
    uint32_t color
) {
    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; sprite[row][col] != '\0'; col++) {

            if (sprite[row][col] != ' ') {

                for (size_t sy = 0; sy < scale; sy++) {
                    for (size_t sx = 0; sx < scale; sx++) {

                        put_pixel(
                            fb,
                            x + col * scale + sx,
                            y + row * scale + sy,
                            color
                        );
                    }
                }
            }
        }
    }
}

//dino eduthath from ascii web swebsite

static const char *dino_sprite[] = {
    "               __",
    "              / _)",
    "     _.----._/ /",
    "    /         /",
    " __/ (  | (  |",
    "/__.-'|_|--|_|"
};




static const char *cactus_sprite[] = {
    "  |",
    "(_|_)",
    "  |"
};



static void game_delay(void) {
    for (volatile uint64_t i = 0; i < 180000; i++) {
        asm volatile ("pause");
    }
}





static const char dino_siva[] =
    "DINO\n"
    "END\n";









static void draw_text(
	struct limine_framebuffer *fb,
	const char *text,
	size_t x,
	size_t y,
	size_t scale,
	uint32_t color
) {
	size_t cursor_x = x;

	for (size_t i = 0; text[i] != '\0'; i++) {

		if (text[i] == ' ') {
			cursor_x += 4 * scale;
			continue;
		}

		draw_char(
			fb,
			text[i],
			cursor_x,
			y,
			scale,
			color
		);

		cursor_x += 6 * scale;
	}
}



static uint8_t inb(uint16_t port){
	uint8_t value;
	asm volatile (
		"inb %1, %0"
		:"=a"(value)
		:"Nd"(port)
	);
	return value;
}

static bool keyboard_has_data(void){
	return (inb(0x64)&1)!=0;
}

static uint8_t keyboard_read(void){
	while (!keyboard_has_data()){

}

	return inb(0x60);
}











static char scancode_to_char(uint8_t scancode){
	switch (scancode){

	  // Number row
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x04: return '3';
        case 0x05: return '4';
        case 0x06: return '5';
        case 0x07: return '6';
        case 0x08: return '7';
        case 0x09: return '8';
        case 0x0A: return '9';
        case 0x0B: return '0';

        // Letters
        case 0x10: return 'Q';
        case 0x11: return 'W';
        case 0x12: return 'E';
        case 0x13: return 'R';
        case 0x14: return 'T';
        case 0x15: return 'Y';
        case 0x16: return 'U';
        case 0x17: return 'I';
        case 0x18: return 'O';
        case 0x19: return 'P';

        case 0x1E: return 'A';
        case 0x1F: return 'S';
        case 0x20: return 'D';
        case 0x21: return 'F';
        case 0x22: return 'G';
        case 0x23: return 'H';
        case 0x24: return 'J';
        case 0x25: return 'K';
        case 0x26: return 'L';

        case 0x2C: return 'Z';
        case 0x2D: return 'X';
        case 0x2E: return 'C';
        case 0x2F: return 'V';
        case 0x30: return 'B';
        case 0x31: return 'N';
        case 0x32: return 'M';

        // Space
        case 0x39: return ' ';

        default:
            return 0;
}
}

static void clear_screen(struct limine_framebuffer *fb){
	volatile uint32_t *pixels = fb->address;

for(size_t y = 0; y < fb -> height; y++){
	for(size_t x =0; x< fb-> width; x++){
	pixels[y * (fb->pitch / 4) + x] = 0x000000;}
	}
} 




static void show_ai(struct limine_framebuffer *fb){
	clear_screen(fb);
	
	draw_text(
	fb,
	"USELESS AI",
	100,
	80,
	6,
	0xFFFFFF
);

	draw_text(
	fb,
	"YOU",
	100,
	180,
	3,
	0xFFFFFF
);

	draw_text(
	fb,
	"ESC BACK",
	100,
	450,
	2,
	0xFFFFFF
);
}

static void show_home(struct limine_framebuffer *fb) {

    clear_screen(fb);

    draw_text(
        fb,
        "USELESS OS",
        100,
        80,
        8,
        0xFFFFFF
    );

    draw_text(
        fb,
        "1 USELESS AI",
        100,
        180,
        4,
        0xFFFFFF
    );

    draw_text(
        fb,
        "2 ABOUT",
        100,
        240,
        4,
        0xFFFFFF
    );

    draw_text(
        fb,
        "3 DINO GAME",
        100,
        300,
        4,
        0xFFFFFF
    );
}


static const char dontpress_siva[] =
    "CLEAR\n"
    "PRINT DO NOT PRESS 1\n"
    "INPUT KEY\n"
    "IF KEY 1\n"
    "PRINT YOU PRESSED IT\n"
    "PRINT GAME OVER\n"
    "END\n";


    static void run_dino_game(struct limine_framebuffer *fb) {
        size_t dino_x = 100;
        size_t dino_y = 300;

        size_t cactus_x = 900;
        size_t cactus_y = 330;

        int time = 0;
        int frame = 0;

        int cactus_count = 0;
        int death_after = (inb(0x60) % 9) + 1;


        for (;;) {

            clear_screen(fb);

            if (cactus_x < 300 && cactus_x > 180) {
                dino_y = 220;
            } else {
                dino_y = 300;
            }

            draw_text(
                fb,
                "DINO RUN",
                60,
                40,
                5,
                0xFFFFFF
            );

            draw_ascii_sprite(
                fb,
                dino_sprite,
                6,
                dino_x,
                dino_y,
                4,
                0xFFFFFF
            );

            draw_ascii_sprite(
                fb,
                cactus_sprite,
                3,
                cactus_x,
                cactus_y,
                4,
                0xFFFFFF
            );

            draw_text(
                fb,
                "RUNNING",
                60,
                500,
                3,
                0xFFFFFF
            );

            if (cactus_x > 60) {
                cactus_x -= 60;
            } else {
                cactus_count++;

                if (cactus_count >= death_after) {
                    break;
                }

                cactus_x = 900;
            }

            frame++;

            if (frame % 10 == 0) {
                time++;
            }

            game_delay();


        }



        clear_screen(fb);

        draw_text(
            fb,
            "DINO DIED",
            100,
            80,
            5,
            0xFFFFFF
        );

        draw_text(
            fb,
            "HOW LONG DID IT RUN",
            100,
            200,
            3,
            0xFFFFFF
        );

        char answer = 0;

        for (;;) {
            uint8_t key = keyboard_read();

            if (key & 0x80) {
                continue;
            }

            if (key == 0x01) {
                return;
            }

            char c = scancode_to_char(key);

            if (c >= '0' && c <= '9') {
                answer = c;
                break;
            }
        }

        char correct_answer = '0' + time;

        clear_screen(fb);

        if (answer == correct_answer) {
            draw_text(
                fb,
                "CORRECT",
                100,
                150,
                5,
                0xFFFFFF
            );
        } else {
            draw_text(
                fb,
                "WRONG",
                100,
                150,
                5,
                0xFFFFFF
            );
        }

        draw_text(
            fb,
            "ESC BACK",
            100,
            300,
            2,
            0xFFFFFF
        );

        for (;;) {
            uint8_t key = keyboard_read();

            if (key == 0x01) {
                return;
            }
        }
    }











static bool starts_with(const char *text, const char *word) {
    size_t i = 0;

    while (word[i] != '\0') {
        if (text[i] != word[i]) {
            return false;
        }

        i++;
    }

    return true;
}






static void run_siva(
    struct limine_framebuffer *fb,
    const char *program
) {
    size_t i = 0;
    size_t cursor_y = 100;

    char key_value = 0;

    while (program[i] != '\0') {

        char line[128];
        size_t line_length = 0;

        while (
            program[i] != '\n' &&
            program[i] != '\0' &&
            line_length < 127
        ) {
            line[line_length] = program[i];

            line_length++;
            i++;
        }

        line[line_length] = '\0';

        if (program[i] == '\n') {
            i++;
        }


        if (starts_with(line, "CLEAR")) {

            clear_screen(fb);

            cursor_y = 100;
        }


        else if (starts_with(line, "PRINT ")) {

            draw_text(
                fb,
                line + 6,
                100,
                cursor_y,
                3,
                0xFFFFFF
            );

            cursor_y += 50;
        }


        else if (starts_with(line, "INPUT KEY")) {

            for (;;) {

                uint8_t key = keyboard_read();

                if (key & 0x80) {
                    continue;
                }

                char c = scancode_to_char(key);

                if (c != 0) {

                    key_value = c;

                    break;
                }
            }
        }


        else if (starts_with(line, "IF KEY ")) {

            char expected = line[7];

            if (key_value != expected) {
                return;
            }
        }


        else if (starts_with(line, "DINO")) {
            run_dino_game(fb);
        }

        else if (starts_with(line, "END")) {
            return;
        }
    }
}


//kmain ivide unde

void kmain(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision) == false) {
        hcf();
    }

    if (framebuffer_request.response == NULL
        || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    struct limine_framebuffer *framebuffer =
        framebuffer_request.response->framebuffers[0];

    show_home(framebuffer);

    for (;;) {
        uint8_t key = keyboard_read();

        if (key == 0x02) {
            show_ai(framebuffer);

            char input[64];
            size_t input_length = 0;

            input[0] = '\0';

            for (;;) {
                uint8_t ai_key = keyboard_read();

                if (ai_key == 0x01) {
                    show_home(framebuffer);
                    break;
                }

                if (ai_key & 0x80) {
                    continue;
                }

                if (ai_key == 0x1C) {
                    draw_text(
                        framebuffer,
                        "I DONT KNOW",
                        100,
                        300,
                        3,
                        0xFFFFFF
                    );

                    continue;
                }

                if (ai_key == 0x0E) {
                    if (input_length > 0) {
                        input_length--;
                        input[input_length] = '\0';

                        show_ai(framebuffer);

                        draw_text(
                            framebuffer,
                            input,
                            200,
                            180,
                            3,
                            0xFFFFFF
                        );
                    }

                    continue;
                }

                char c = scancode_to_char(ai_key);

                if (c != 0 && input_length < 63) {
                    input[input_length] = c;
                    input_length++;
                    input[input_length] = '\0';

                    draw_text(
                        framebuffer,
                        input,
                        200,
                        180,
                        3,
                        0xFFFFFF
                    );
                }
            }
        }



else if (key == 0x04) {

    run_siva(
        framebuffer,
        dino_siva
    );

    show_home(framebuffer);
}


        else if (key == 0x03) {
            clear_screen(framebuffer);

            draw_text(
                framebuffer,
                "ABOUT",
                100,
                80,
                5,
                0xFFFFFF
            );

            draw_text(
                framebuffer,
                "USELESS OS V01",
                100,
                180,
                3,
                0xFFFFFF
            );

            draw_text(
                framebuffer,
                "CREATED BY",
                100,
                230,
                3,
                0xFFFFFF
            );

            draw_text(
                framebuffer,
                "SIVADARSH P DINESH",
                100,
                280,
                3,
                0xFFFFFF
            );

            draw_text(
                framebuffer,
                "ESC TO GO  BACK",
                100,
                400,
                2,
                0xFFFFFF
            );
        }

        else if (key == 0x01) {
            show_home(framebuffer);
        }
    }
}











// The following will be our kernel's entry point.
// If renaming kmain() to something else, make sure to change the
// linker script accordingly.

/*
uint8_t key = keyboard_read();

// ANY received keyboard byte should change the screen
for (size_t y = 0; y < framebuffer->height; y++) {
    for (size_t x = 0; x < framebuffer->width; x++) {
        fb_ptr[y * (framebuffer->pitch / 4) + x] = 0x000000;
    }
}

draw_text(
    framebuffer,
    "KEY",
    100,
    150,
    8,
    0xFFFFFF
);

*/

