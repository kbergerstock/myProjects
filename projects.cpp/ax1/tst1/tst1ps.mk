
tst1ps.dll: dlldata.obj tst1_p.obj tst1_i.obj
	link /dll /out:tst1ps.dll /def:tst1ps.def /entry:DllMain dlldata.obj tst1_p.obj tst1_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del tst1ps.dll
	@del tst1ps.lib
	@del tst1ps.exp
	@del dlldata.obj
	@del tst1_p.obj
	@del tst1_i.obj
