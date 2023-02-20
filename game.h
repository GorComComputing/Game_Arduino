#ifndef GAME_H
#define GAME_H

#define AddEnemy(a,b) ObjectInit(NewObject(), a, b, 8, 8, 'e') // Макрос создания врагов


// Положение объектов
typedef struct SPoint{
    float x, y;
} TPoint;


// Объект
typedef struct SObject{
    TPoint pos;
    TPoint size;
    //COLORREF brush;
    TPoint speed;
    char oType;
    bool isDel;
    //BOOL sprite;
} TObject, *PObject;


#endif // GAME_H
