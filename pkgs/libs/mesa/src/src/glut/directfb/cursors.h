#ifndef __GLUT_CURSORS_H__
#define __GLUT_CURSORS_H__


static const unsigned char cur_right_arrow[] = {
     16, /* size */
     1, 2, /* hotspot */
     /* data */
     0x00, 0x00, 0x60, 0x00, 0x78, 0x00, 0x3e, 0x00, 
     0x3f, 0x80, 0x1f, 0xe0, 0x1f, 0xf8, 0x0f, 0x80, 
     0x0f, 0xc0, 0x06, 0xe0, 0x06, 0x70, 0x02, 0x38, 
     0x02, 0x1c, 0x00, 0x0e, 0x00, 0x04, 0x00, 0x00, 
     /* mask */
     0xe0, 0x00, 0xf8, 0x00, 0xfe, 0x00, 0x7f, 0x80, 
     0x7f, 0xe0, 0x3f, 0xf8, 0x3f, 0xfc, 0x1f, 0xfc, 
     0x1f, 0xe0, 0x0f, 0xf0, 0x0f, 0xf8, 0x07, 0x7c, 
     0x07, 0x3e, 0x02, 0x1f, 0x00, 0x0e, 0x00, 0x04, 
};

static const unsigned char cur_left_arrow[] = {
     16, /* size */
     1, 15, /* hotspot */
     /* data */
     0x00, 0x00, 0x80, 0x06, 0x00, 0x1e, 0x00, 0x7c, 
     0x01, 0xfc, 0x07, 0xf8, 0x1f, 0xf8, 0x01, 0xf0, 
     0x01, 0xf0, 0x02, 0x60, 0x04, 0x60, 0x08, 0x40, 
     0x10, 0x40, 0x20, 0x00, 0x40, 0x00, 0x00, 0x00, 
     /* mask */
     0x00, 0x07, 0x00, 0x1f, 0x00, 0x7f, 0x01, 0xfe, 
     0x07, 0xfe, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xf8, 
     0x03, 0xf8, 0x07, 0xf0, 0x0e, 0xf0, 0x1c, 0xe0, 
     0x38, 0xe0, 0x70, 0xe0, 0xe0, 0x00, 0xc0, 0x00, 
};

static const unsigned char cur_info[] = {
     16, /* size */
     0, 2, /* hotspot */
     /* data */
     0x30, 0x00, 0x3c, 0x00, 0x0f, 0x00, 0x07, 0x80, 
     0x03, 0xc0, 0x07, 0xe0, 0x0f, 0xf0, 0x07, 0xf4, 
     0x0f, 0xfe, 0x0f, 0xfa, 0x07, 0xe0, 0x03, 0xe0, 
     0x00, 0x52, 0x00, 0x46, 0x00, 0x2c, 0x00, 0x18, 
     /* mask */
     0xb8, 0x00, 0x3e, 0x00, 0x1f, 0x80, 0x0f, 0xc0, 
     0x07, 0xe0, 0x0f, 0xf0, 0x1f, 0xfc, 0x1f, 0xfe, 
     0x1f, 0xfe, 0x1f, 0xfe, 0x0f, 0xfe, 0x07, 0xfe, 
     0x03, 0xfe, 0x00, 0xfe, 0x00, 0x7e, 0x00, 0x3c, 
};

static const unsigned char cur_destroy[] = {
     16, /* size */
     12, 8, /* hotspot */
     /* data */
     0x01, 0xe0, 0x03, 0xf0, 0x07, 0xf8, 0x0c, 0xcc, 
     0x0c, 0xcc, 0x07, 0xf8, 0x03, 0xf0, 0x01, 0xe0, 
     0x21, 0xe1, 0x61, 0xe1, 0x10, 0xc2, 0x0e, 0x1c, 
     0x01, 0xe0, 0x47, 0xf8, 0x7c, 0x0f, 0x20, 0x01, 
     /* mask */
     0x03, 0xf0, 0x07, 0xf8, 0x0f, 0xfc, 0x1f, 0xfe, 
     0x1f, 0xfe, 0x0f, 0xfc, 0x07, 0xf8, 0x83, 0xf1, 
     0xe3, 0xf1, 0xf3, 0xf3, 0x39, 0xef, 0x1e, 0x1e, 
     0x01, 0xe0, 0xc7, 0xfe, 0xff, 0xff, 0x7c, 0x0f, 
};

static const unsigned char cur_help[] = {
     16, /* size */
     7, 8, /* hotspot */
     /* data */
     0x83, 0xe0, 0x07, 0xf0, 0x0e, 0x38, 0x0c, 0x18, 
     0x0c, 0x38, 0x0e, 0x30, 0x07, 0x00, 0x03, 0xc0, 
     0x01, 0xc0, 0x01, 0x40, 0x01, 0x40, 0x07, 0x70, 
     0x03, 0x60, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00, 
     /* mask */
     0x03, 0xe0, 0x07, 0xf0, 0x0f, 0xf8, 0x1f, 0xfc, 
     0x1e, 0x3c, 0x1e, 0x7c, 0x1f, 0x78, 0x0f, 0xf0, 
     0x07, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 0x07, 0xf0, 
     0x0f, 0xf8, 0x07, 0xf0, 0x03, 0xe0, 0x01, 0xc0, 
};

static const unsigned char cur_cycle[] = {
     16, /* size */
     7, 9, /* hotspot */
     /* data */
     0x00, 0x00, 0x07, 0xe2, 0x0f, 0xf6, 0x18, 0x3e, 
     0x10, 0x12, 0x00, 0x32, 0x00, 0x7e, 0x00, 0x00, 
     0x00, 0x00, 0x7e, 0x00, 0x4c, 0x00, 0x48, 0x08, 
     0x7c, 0x18, 0x6f, 0xf0, 0x47, 0xe0, 0x00, 0x00, 
     /* mask */
     0x07, 0xe3, 0x0f, 0xf7, 0x1f, 0xff, 0x3f, 0xff, 
     0x38, 0x3f, 0x30, 0xff, 0x00, 0xff, 0x00, 0xff, 
     0xff, 0x00, 0xff, 0x00, 0xfe, 0x0c, 0xfc, 0x1c, 
     0xff, 0xfc, 0xff, 0xf8, 0xef, 0xf0, 0xc7, 0xe0, 
};

static const unsigned char cur_spray[] = {
     16, /* size */
     2, 4, /* hotspot */
     /* data */
     0x98, 0x00, 0x02, 0x00, 0x18, 0xb0, 0x02, 0x78, 
     0x18, 0x58, 0x00, 0xfc, 0x00, 0x84, 0x00, 0x9c, 
     0x00, 0x94, 0x00, 0x9c, 0x00, 0x94, 0x00, 0x9c, 
     0x00, 0x9c, 0x00, 0x84, 0x00, 0x84, 0x00, 0xfc, 
     /* mask */
     0x30, 0x00, 0x34, 0x60, 0x35, 0xf0, 0x35, 0xf0, 
     0x35, 0xf8, 0x03, 0xfc, 0x03, 0xfc, 0x03, 0xfc, 
     0x03, 0xfc, 0x03, 0xfc, 0x03, 0xfc, 0x03, 0xfc, 
     0x03, 0xfc, 0x03, 0xfc, 0x03, 0xfc, 0x03, 0xfc, 
};

static const unsigned char cur_wait[] = {
     16, /* size */
     9, 1, /* hotspot */
     /* data */
     0x07, 0xf8, 0x07, 0xf8, 0x07, 0xf8, 0x0f, 0xfc, 
     0x18, 0x86, 0x30, 0x83, 0xe0, 0x81, 0xe1, 0xc1, 
     0xe1, 0xc1, 0xe0, 0x21, 0x30, 0x13, 0x18, 0x06, 
     0x0f, 0xfc, 0x07, 0xf8, 0x07, 0xf8, 0x07, 0xf8, 
     /* mask */
     0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xfc, 0x1f, 0xfe, 
     0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 
     0x1f, 0xfe, 0x0f, 0xfc, 0x0f, 0xfc, 0x0f, 0xfc, 
};

static const unsigned char cur_text[] = {
     16, /* size */
     8, 8, /* hotspot */
     /* data */
     0x00, 0x00, 0x0f, 0x70, 0x09, 0xc0, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x01, 0xc0, 0x07, 0x70, 0x00, 0x00, 
     /* mask */
     0x0f, 0x78, 0x0f, 0xf8, 0x0f, 0xf8, 0x03, 0xe0, 
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
     0x03, 0xe0, 0x0f, 0xf8, 0x0f, 0xf8, 0x0f, 0x78, 
};

static const unsigned char cur_crosshair[] = {
     16, /* size */
     7, 9, /* hotspot */
     /* data */
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0xff, 0x7f, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
     /* mask */
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
     0x01, 0xc0, 0x01, 0xc0, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
};

static const unsigned char cur_up_down[] = {
     16, /* size */
     7, 8, /* hotspot */
     /* data */
     0x00, 0x80, 0x09, 0xc0, 0x03, 0xe0, 0x07, 0xf0, 
     0x01, 0x40, 0x01, 0x40, 0x01, 0x40, 0x01, 0x40, 
     0x01, 0x40, 0x01, 0x40, 0x01, 0x40, 0x07, 0xf0, 
     0x03, 0xe0, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00, 
     /* mask */
     0x01, 0xc0, 0x03, 0xe0, 0x07, 0xf0, 0x0f, 0xf8, 
     0x0f, 0xf8, 0x03, 0xe0, 0x03, 0xe0, 0x03, 0xe0, 
     0x03, 0xe0, 0x03, 0xe0, 0x0f, 0xf8, 0x0f, 0xf8, 
     0x07, 0xf0, 0x03, 0xe0, 0x01, 0xc0, 0x00, 0x00, 
};

static const unsigned char cur_left_right[] = {
     16, /* size */
     7, 8, /* hotspot */
     /* data */
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     0x08, 0x08, 0x18, 0x0c, 0x3f, 0xfe, 0x78, 0x0f, 
     0x3f, 0xfe, 0x18, 0x0c, 0x08, 0x08, 0x00, 0x00, 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
     /* mask */
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8c, 0x18, 
     0x1c, 0x1c, 0x3f, 0xfe, 0x7f, 0xff, 0x7f, 0xff, 
     0x7f, 0xff, 0x3f, 0xfe, 0x1c, 0x1c, 0x0c, 0x18, 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char cur_top_side[] = {
     16, /* size */
     1, 8, /* hotspot */
     /* data */
     0x00, 0x00, 0xff, 0xfe, 0x3f, 0xfe, 0x00, 0x00, 
     0x00, 0x80, 0x01, 0xc0, 0x02, 0xa0, 0x04, 0x90, 
     0x08, 0x88, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
     /* mask */
     0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
     0x01, 0xc0, 0x03, 0xe0, 0x07, 0xf0, 0x0f, 0xf8, 
     0x1d, 0xdc, 0x19, 0xcc, 0x01, 0xc0, 0x01, 0xc0, 
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
};

static const unsigned char cur_bottom_side[] = {
     16, /* size */
     14, 8, /* hotspot */
     /* data */
     0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
     0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x08, 0x88, 
     0x04, 0x90, 0x02, 0xa0, 0x01, 0xc0, 0x00, 0x80, 
     0x00, 0x00, 0x3f, 0xfe, 0x3f, 0xfe, 0x00, 0x00, 
     /* mask */
     0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 
     0x01, 0xc0, 0x01, 0xc0, 0x19, 0xcc, 0x1d, 0xdc, 
     0x0f, 0xf8, 0x07, 0xf0, 0x03, 0xe0, 0x01, 0xc0, 
     0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 
};

static const unsigned char cur_left_side[] = {
     16, /* size */
     7, 15, /* hotspot */
     /* data */
     0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x01, 0x06, 
     0x00, 0x86, 0x00, 0x46, 0x00, 0x26, 0x7f, 0xf6, 
     0x00, 0x26, 0x00, 0x46, 0x00, 0x86, 0x01, 0x06, 
     0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 
     /* mask */
     0x00, 0x0f, 0x00, 0x0f, 0x03, 0x0f, 0x03, 0x8f, 
     0x01, 0xcf, 0x00, 0xef, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0x00, 0xef, 0x01, 0xcf, 0x03, 0x8f, 
     0x03, 0x0f, 0x00, 0x0f, 0x00, 0x0f, 0x00, 0x00, 
};

static const unsigned char cur_right_side[] = {
     16, /* size */
     7, 2, /* hotspot */
     /* data */
     0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0x60, 0x80, 
     0x61, 0x00, 0x62, 0x00, 0x64, 0x00, 0x6f, 0xfe, 
     0x64, 0x00, 0x62, 0x00, 0x61, 0x00, 0x60, 0x80, 
     0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 
     /* mask */
     0xf0, 0x00, 0xf0, 0x00, 0xf0, 0xc0, 0xf1, 0xc0, 
     0xf3, 0x80, 0xf7, 0x00, 0xff, 0xff, 0xff, 0xff, 
     0xff, 0xff, 0xf7, 0x00, 0xf3, 0x80, 0xf1, 0xc0, 
     0xf0, 0xc0, 0xf0, 0x00, 0xf0, 0x00, 0x00, 0x00, 
};

static const unsigned char cur_top_left[] = {
     16, /* size */
     1, 15, /* hotspot */
     /* data */
     0x00, 0x00, 0xff, 0xfe, 0x7f, 0xfe, 0x00, 0x06, 
     0x00, 0x06, 0x00, 0x06, 0x1f, 0xc6, 0x00, 0xc6, 
     0x01, 0x46, 0x02, 0x46, 0x04, 0x46, 0x08, 0x46, 
     0x10, 0x46, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 
     /* mask */
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0x00, 0x0f, 0x3f, 0xef, 0x3f, 0xef, 0x3f, 0xef, 
     0x03, 0xef, 0x07, 0xef, 0x0e, 0xef, 0x1c, 0xef, 
     0x38, 0xef, 0x30, 0xef, 0x00, 0x0f, 0x00, 0x0f, 
};

static const unsigned char cur_top_right[] = {
     16, /* size */
     1, 2, /* hotspot */
     /* data */
     0x00, 0x00, 0xff, 0xfe, 0x7f, 0xfe, 0x60, 0x00, 
     0x60, 0x00, 0x60, 0x00, 0x63, 0xf8, 0x63, 0x00, 
     0x62, 0x80, 0x62, 0x40, 0x62, 0x20, 0x62, 0x10, 
     0x62, 0x08, 0x60, 0x00, 0x60, 0x00, 0x00, 0x00, 
     /* mask */
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
     0xf0, 0x00, 0xf7, 0xfc, 0xf7, 0xfc, 0xf7, 0xfc, 
     0xf7, 0xc0, 0xf7, 0xe0, 0xf7, 0x70, 0xf7, 0x38, 
     0xf7, 0x1c, 0xf7, 0x0c, 0xf0, 0x00, 0xf0, 0x00, 
};

static const unsigned char cur_bottom_right[] = {
     16, /* size */
     14, 2, /* hotspot */
     /* data */
     0x00, 0x00, 0x60, 0x00, 0x60, 0x00, 0x62, 0x08, 
     0x62, 0x10, 0x62, 0x20, 0x62, 0x40, 0x62, 0x80, 
     0x63, 0x00, 0x63, 0xf8, 0x60, 0x00, 0x60, 0x00, 
     0x60, 0x00, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00, 
     /* mask */
     0xf0, 0x00, 0xf0, 0x00, 0xf7, 0x0c, 0xf7, 0x1c, 
     0xf7, 0x38, 0xf7, 0x70, 0xf7, 0xe0, 0xf7, 0xc0, 
     0xf7, 0xfc, 0xf7, 0xfc, 0xf7, 0xfc, 0xf0, 0x00, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};

static const unsigned char cur_bottom_left[] = {
     16, /* size */
     14, 15, /* hotspot */
     /* data */
     0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x10, 0x46, 
     0x08, 0x46, 0x04, 0x46, 0x02, 0x46, 0x01, 0x46, 
     0x00, 0xc6, 0x1f, 0xc6, 0x00, 0x06, 0x00, 0x06, 
     0x00, 0x06, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00, 
     /* mask */
     0x00, 0x0f, 0x00, 0x0f, 0x30, 0xef, 0x38, 0xef, 
     0x1c, 0xef, 0x0e, 0xef, 0x07, 0xef, 0x03, 0xef, 
     0x3f, 0xef, 0x3f, 0xef, 0x3f, 0xef, 0x00, 0x0f, 
     0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};


#endif /* __GLUT_CURSORS_H__ */
