#if !defined(_RL_ENCRYPTOR_02_H__B72364868609__INCLUDED_)
#define _RL_ENCRYPTOR_02_H__B72364868609__INCLUDED_

#define RLEncryptor02_L 4   // the same in SEAL L=32768

class RLEncryptor02
{
public:
	RLEncryptor02();
	~RLEncryptor02();

	void Copy(const RLEncryptor02& src);
	void FastCopy(const RLEncryptor02& src);

	void Encrypt(UINT8 *input, int count);
	void Decrypt(UINT8 *input, int count);
	void SetKey(const UINT8 *key, bool encryption);

private:
	inline void RotateEncr(UINT8 *input, int count);
	inline void RotateDecr(UINT8 *input, int count);
	inline void XORCrypt  (UINT8 *input, int count);
	static void SHATransform(UINT32 *digest, const UINT32 *data);

	inline void   Gamma(const UINT32 *key);
	inline UINT32 GammaApply(UINT32 i);
	inline void   IncrementCounter();
	       void   Generate();

private:
	UINT   m_counter;
	UINT   m_position;
	UINT32 m_lastIndex;
	UINT32 H[5], Z[5], D[16], S[256], T[512], R[4*RLEncryptor02_L];
	UINT8  m_buffer[4096];
	
	UINT8  m_rotation[256];
	int    m_prevByte; // should be UINT8, but int works faster, it's needed for Rotate() - input depended
};

#endif // !defined(_RL_ENCRYPTOR_02_H__B72364868609__INCLUDED_)
