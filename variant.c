enum Variant_Type {UNDEFINED = 0, 
  CHAR, UCHAR, SCHAR,
  USHORT, SSHORT,
  UINT, SINT,
  ULONG,SLONG,
  ULONGLONG, SLONGLONG,
  FLOAT, DOUBLE, LONGDOUBLE, POINTER}
  
  struct variant {
    union {
      char c;
      unsigned char uc;
      signed char sc;
      unsigned short us;
      signed short ss;
      unsigned int ui;
    };
    enum Variant_Type type;
  }
