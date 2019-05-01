#ifndef POSITION
#define POSITION

class Position {
private:
	float posX;
	float posY;

	float oldPosX;
	float oldPosY;
public:
	Position();
	/**
	@param posX po��te�n� pozice na ose X
	@param posY Tpo��te�n� pozice na ose Y
	*/
	Position(float posX, float posY);
	~Position();
	/**
	@return pozice na ose X
	*/
	int getPosX();
	/**
	@return pozice na ose Y
	*/
	int getPosY();
	/**
	Nastav� pozici

	@param posX pozice na ose X
	*/
	void setPosX(float posX);
	/**
	Nastav� pozici

	@param posY pozice na ose Y
	*/
	void setPosY(float posY);
	/**
	@return p�edchoz� pozice na ose X
	*/
	int getOldPosX();
	/**
	@return p�edchoz� pozice na ose Y
	*/
	int getOldPosY();
	/**
	Nastav� star� pozice na aktu�ln�
	*/
	void setNewOldPosition();
	/**
	@return informace zdali do�lo ke zm�n� pozice
	*/
	bool isPositionChanged();
	/**
	@return informace zdali do�lo ke zm�n� pozice na ose X
	*/
	bool isPositionXChanged();
	/**
	@return informace zdali do�lo ke zm�n� pozice na ose Y
	*/
	bool isPositionYChanged();
};

#endif // !POSITION
