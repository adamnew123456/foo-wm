char * handleCommand(char * request);
char * nextToken(char ** tokenString);

void absorb(char * argA, char * argB);
void containerize(void);
void focus(char * argA, char * argB);
char * get(char * property);
void kill(void);
void jump(char * markName);
void layout(char * l);
void mark(char * markName);
void set(char * property, char * value);
void shift(char * argA, int delta);
Bool swap(char * argA , char * argB);
void zoom(int level);
