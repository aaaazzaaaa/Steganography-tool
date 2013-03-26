/* Minimal portable random generator by Park and Miller */

/* Lewis-Goodman-Miller constants */
#define IA 16807
#define IM 2147483647
#define AM (1./IM)
/* Scharge constants */
#define IQ 12773
#define IR 2836
/* Special mask to be explained below */
#define MASK 123456789

static long dummy;

/* initial seed, for all the generators here */
void Seed(long dum) {dummy=dum;}

/* returns random uniformly distributed between 0 and 1 */
float unirand0(void) {
 long k;
 float ans;
 dummy^=MASK;	/* avoid dummy==0 */
 k=dummy/IQ;
 if((dummy=IA*(dummy-k*IQ)-IR*k)<0) dummy+=IM;
 ans=AM*dummy;
 dummy^=MASK;	/* restore unmasked dummy */
 return(ans);
}