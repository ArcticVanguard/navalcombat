#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Define */
#define MAXFPS 30
#define MAXUNITS 5
#define WINDOWWIDTH 256
#define WINDOWHEIGHT 450

/* Typedefs */
typedef struct {
	bool isalive;
	bool player;
	int ammo;
	/* Physics variables */
	float coords[2];
	float movevect[2];
	int heading;
	float mass;
	int velocity;
	float acceleration;
	float maxvel;
	int collisionbox[2];
	int rotationspeed;
} Mook;

typedef struct {
	unsigned int ammo;
	int coords[2];
} Crate;

/* Function declaration */
float calcforce(float m, float a);
static Crate *createcrate(unsigned int a, int* c);
static Mook *createmook(int a, bool p, int *cb, float *c, int h, float ms, int mv, int rs);
void die(const char *errstr, ...);
static void seedrand(void);
static int genrand(int a);
int *gencoords(void);

/* Function definitions */

float calcforce(float m, float a) {
	float ret;
	ret = m * a;
	return ret;
}

Crate *
createcrate(unsigned int a, int* c) {
	Crate *r;
	if(!(r = (Crate *)calloc(1, sizeof(Crate))))
		die("fatal: could not malloc() %u bytes\n", sizeof(Crate));
	r->ammo      = a;
	r->coords[0] = c[0];
	r->coords[1] = c[1];
	return r;
}


Mook *
createmook(int a, bool p, int *cb, float *c, int h, float ms, int mv, int rs) {
	Mook *m;
	if(!(m = (Mook *)calloc(1, sizeof(Mook))))
		die("fatal: could not malloc() %u bytes\n", sizeof(Mook));
	m->ammo            = a;
	m->isalive         = true;
	m->player          = p;

	m->acceleration    = 0;
	m->collisionbox[0] = cb[0];
	m->collisionbox[1] = cb[1];
	m->coords[0]       = c[0];
	m->coords[1]       = c[1];
	m->heading         = h;
	m->mass            = ms;
	m->maxvel          = mv;
	m->rotationspeed   = rs;
	m->velocity        = 0;

	return m;
}

/* Comes from dwm by the fine people of suckless.org */
void
die(const char *errstr, ...) {
	va_list ap;

	va_start(ap, errstr);
	vfprintf(stderr, errstr, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

int *
gencoords(void) {
	static int ret[2];
	ret[0]=genrand(WINDOWWIDTH);
	ret[1]=genrand(WINDOWHEIGHT);
	return ret;
}

int
genrand(int a) {
	int r = rand();
	return r % a;
}

void seedrand(void) { srand(time(NULL)); }

/* Main */
void main() {
	return;
}
