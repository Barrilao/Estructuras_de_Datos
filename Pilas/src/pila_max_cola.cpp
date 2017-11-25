void Pila_max::quitar()
{
  Cola<elemento> aux;

  int size = num_elementos() -1;

  for (int i = 0; i<size; i++)
  {
    aux.poner(datos.frente());
    datos.quitar();
  }

  datos = aux;

}

elemento Pila_max::tope()
{
  Cola<elemento> aux = datos;

  elemento elem = aux.frente();

  while (!aux.vacia())
  {
      elem.ele = aux.frente().ele;
      elem.maximo = aux.frente().maximo;
      aux.quitar();
  }

  return elem;
}

void Pila_max::poner(int valor)
{
  elemento nuevo;
  nuevo.ele = valor;

  if (vacia())
  {
    nuevo.maximo = valor;
  }
  else
  {
    elemento anterior = tope();
    nuevo.maximo = (valor > anterior.maximo) ? valor : anterior.maximo;

  }
  datos.poner(nuevo);
}
