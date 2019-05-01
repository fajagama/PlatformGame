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
	@param posX poèáteèní pozice na ose X
	@param posY Tpoèáteèní pozice na ose Y
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
	Nastaví pozici

	@param posX pozice na ose X
	*/
	void setPosX(float posX);
	/**
	Nastaví pozici

	@param posY pozice na ose Y
	*/
	void setPosY(float posY);
	/**
	@return pøedchozí pozice na ose X
	*/
	int getOldPosX();
	/**
	@return pøedchozí pozice na ose Y
	*/
	int getOldPosY();
	/**
	Nastavý staré pozice na aktuální
	*/
	void setNewOldPosition();
	/**
	@return informace zdali došlo ke zmìnì pozice
	*/
	bool isPositionChanged();
	/**
	@return informace zdali došlo ke zmìnì pozice na ose X
	*/
	bool isPositionXChanged();
	/**
	@return informace zdali došlo ke zmìnì pozice na ose Y
	*/
	bool isPositionYChanged();
};

#endif // !POSITION
