//Top level IMPLICIT Declarations

VALUE spicerub_top_module;
VALUE spicerub_nested_module;
VALUE rb_spice_error;

const size_t VECTOR_SHAPE[2] = {1,3};
const size_t STATE_SHAPE[2] = {1,6};

//Kernel Loading Functions
static VALUE furnsh(VALUE self, VALUE kernel);
static VALUE unload(VALUE self, VALUE kernel);
static VALUE ktotal(int argc, VALUE *argv, VALUE self);
static VALUE kclear(VALUE self);

//Geometry and Co-ordinate System Function
static VALUE latrec(VALUE self, VALUE radius, VALUE longtitude, VALUE latitude);
static VALUE  lspcn(int argc, VALUE *argv, VALUE self);
static VALUE reclat(VALUE self, VALUE rectangular_point);
static VALUE sincpt(VALUE self, VALUE method, VALUE target, VALUE et, VALUE fixref, VALUE abcorr, VALUE obsrvr, VALUE dref, VALUE dvec);
static VALUE subpnt(VALUE self, VALUE method, VALUE target, VALUE et, VALUE fixref, VALUE abcorr, VALUE obsrvr);
static VALUE subslr(VALUE self, VALUE method, VALUE target, VALUE et, VALUE fixref, VALUE abcorr, VALUE obsrvr);
static VALUE recsph(VALUE self, VALUE rectangular);
static VALUE sphrec(VALUE self, VALUE radius, VALUE colatitude, VALUE longitude);
static VALUE phaseq(VALUE self, VALUE et, VALUE target, VALUE illmn, VALUE obsrvr, VALUE abcorr);
static VALUE recrad(VALUE self, VALUE rectangular);
static VALUE radrec(VALUE self, VALUE range, VALUE right_ascension, VALUE declination);
static VALUE recgeo(VALUE self, VALUE rectangular, VALUE radius_equatorial, VALUE flattening);
static VALUE georec(VALUE self, VALUE longitude, VALUE latitude, VALUE altitude, VALUE radius_equatorial, VALUE flattening);
static VALUE recpgr(VALUE self, VALUE body, VALUE rectangular, VALUE radius_equatorial, VALUE flattening);
static VALUE pgrrec(VALUE self, VALUE body, VALUE longitude, VALUE latitude, VALUE altitude, VALUE radius_equatorial, VALUE flattening);
static VALUE dpr(VALUE self);
static VALUE rpd(VALUE self);
static VALUE getfov(VALUE self, VALUE instid, VALUE room, VALUE shapelen, VALUE framelen);
static VALUE bodvrd(VALUE self, VALUE bodynm, VALUE item, VALUE maxn);

//Time and Time Conversions Functions
static VALUE str2et(VALUE self, VALUE epoch);


//Helper Macros

//Macros for switch parameters in error message reports
#define SPICE_ERROR_SHORT 0
#define SPICE_ERROR_LONG 1
#define SPICE_ERROR_EXPLAIN 2
#define SPICE_ERROR_ALL 3

//Macros for simplifying frequent operations
// Converts a Ruby Symbol to C string
#define RB_SYM2STR(val) (rb_id2name(SYM2ID(val)))
#define RB_STR2SYM(val) (ID2SYM(rb_intern(val)))