#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
@ i = $inicio
echo > ejercicio_desc.dat
while ( $i <= $fin )
	echo Ejecución tam = $i
	echo `./ejercicio_desc $i` >> ejercicio_desc.dat
	@ i += $incremento
end
