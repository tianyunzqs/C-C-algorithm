#if !defined(_INITGDIPLUS_H_)
#define _INITGDIPLUS_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <gdiplus.h>

class InitGDIPlus {
private:
	HANDLE							m_hMap;
	bool							m_bInited, m_bInitCtorDtor;
	ULONG_PTR						m_gdiplusToken;
	Gdiplus::GdiplusStartupInput	m_gdiplusStartupInput;
	long							m_initcount;

public:
	// Constructor offers the ability to initialize on construction, or delay until needed.
	InitGDIPlus(bool bInitCtorDtor = false) : m_bInitCtorDtor(bInitCtorDtor), 
				m_bInited(false), m_hMap(NULL), m_gdiplusToken(NULL), 
				m_gdiplusStartupInput(NULL), m_initcount(0)  
	{
		if (m_bInitCtorDtor) {
			Initialize();
		}
	}

	// If GDI+ has not explicitly been Deinitialized, do it in the destructor
	virtual ~InitGDIPlus()  {
		if (m_bInitCtorDtor) {
			Deinitialize();
		}
	}

	// This function creates a file mapping based on the current process id.
	// If the mapping already exists, it knows that another instance of this class
	// elsewhere in the process has already taken care of starting GDI+.
	void Initialize() {
		if (!m_bInited) {
			char buffer[1024];
			sprintf(buffer, "GDIPlusInitID=%x", GetCurrentProcessId());
			m_hMap = CreateFileMapping((HANDLE) INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE | SEC_COMMIT, 0, sizeof(long), buffer);
			if (m_hMap != NULL) {
				// We might have a winner
				if (GetLastError() == ERROR_ALREADY_EXISTS) { 
					CloseHandle(m_hMap); 
				} else {
					// Yes, we have a winner
					m_bInited = true;
					Gdiplus::GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);
					TRACE("Inited GDIPlus\n");
				}
			}
		}
		m_initcount++;
	}

	// No tricks to this function.  If this was the class that originally started GDI+,
	// and its initialization count has reached zero, it shuts down GDI+.
	void Deinitialize()
	{
		m_initcount--;
		if (m_bInited && m_initcount == 0) {
			TRACE("GDIPlus shutdown\n");
			Gdiplus::GdiplusShutdown(m_gdiplusToken);
			CloseHandle(m_hMap);
			m_bInited = false;
		}
	}
};

#endif