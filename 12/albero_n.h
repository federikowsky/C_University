#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int TipoInfoAlbero;

struct StructNodoFiglio;

struct StructAlbero {
	TipoInfoAlbero info;
	struct StructNodoFiglio * figli;
};

struct StructNodoFiglio {
	struct StructAlbero * albero;
	struct StructNodoFiglio * next;
};

typedef struct StructAlbero * TipoAlbero;
typedef struct StructNodoFiglio * TipoFigli;
