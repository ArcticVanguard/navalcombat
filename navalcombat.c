/* Include */
#include <stdlib.h>
#include <stdio.h>

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
	const int collisionbox[2];
	const int rotationspeed;
} Mook;

typedef struct {
	const unsigned int ammo;
	const int coords[2];
} Crate;

/* Function declaration */
float calcforce(float m, float a);
static Crate *createcrate(const unsigned int a, const int* c);
static Mook *createmook(int a, bool p, int *cb, float *c, int h, float ms, int mv, int rs);
void die(const char *errstr, ...);
int *genCoords();

/* Function definitions */

float calcforce(float m, float a) {
	float ret;
	ret = m * a;
	return ret;
}

Crate *
createcrate(const unsigned int a, const int* c) {
	Crate *r;
	if(!(m = (Crate *)calloc(1, sizeof(Crate))))
		die("fatal: could not malloc() %u bytes\n", sizeof(Crate));
	r->ammo   = a;
	r->coords = &c;
	return r;
}


Mook *
createmook(int a, bool p, int *cb, float *c, int h, float ms, int mv, int rs) {
	Mook *m;
	if(!(m = (Mook *)calloc(1, sizeof(Mook))))
		die("fatal: could not malloc() %u bytes\n", sizeof(Mook));
	m->ammo          = a;
	m->isalive       = true;
	m->player        = p;

	m->acceleration  = 0;
	m-collisionbox   = &cb;
	m->coords        = &c;
	m->heading       = h;
	m->mass          = ms;
	m->maxvel        = mv;
	m->rotationspeed = rs;
	m->velocity      = 0;

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

int
*genCoords() {
	static int ret[2];
	ret[0]=random(WINDOWWIDTH);
	ret[1]=random(WINDOWHEIGHT);
	return ret;
}

/* Main */
void main() {
}
