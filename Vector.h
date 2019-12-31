template <typename T>
class Vector
{
public:
	Vector() : Vector(128) {}

	Vector(int iBufferSize)
	{
		this->m_pBuffer = new T[this->m_iBufferSize = iBufferSize];
	}

	void Push(T tValue)
	{
		if (this->m_iVarsCount >= this->m_iBufferSize / sizeof(T))
			this->ReAlloc();

		this->m_pBuffer[this->m_iVarsCount++] = tValue;
	}

	void Pop()
	{
		this->m_pBuffer[--this->m_iVarsCount].~T();
	}

	T& At(int i)
	{
		return this->m_pBuffer[i];
	}

	T& operator[](int i)
	{
		return this->m_pBuffer[i];
	}

	int Size()
	{
		return this->m_iVarsCount;
	}

	void Clear()
	{
		for (int i = 0; i < this->m_iVarsCount; ++i)
			this->m_pBuffer[i].~T();
		this->m_iVarsCount = 0;
	}

	T* GetBuffer()
	{
		return this->m_pBuffer;
	}

	T* begin()
	{
		return this->m_pBuffer;
	}

	T* end()
	{
		return this->m_pBuffer + this->m_iVarsCount;
	}

private:
	T* m_pBuffer = nullptr;
	int m_iBufferSize = 0;
	int m_iVarsCount = 0;

	void ReAlloc()
	{
		T* pTemp = new T[this->m_iBufferSize];
		for (int i = 0; i < (this->m_iBufferSize = ((this->m_iVarsCount + 1) * sizeof(T))); i++)
			pTemp[i] = this->m_pBuffer[i];
		delete[] this->m_pBuffer;
		this->m_pBuffer = pTemp;
	}
};