program Exemplo;

var
  numero: integer;
  media: real;

begin
  write('Digite um numero: ');
  read(numero);

  if numero > 0 then
  begin
    media := numero / 2;
    write('A metade do numero digitado e: ', media);
  end
  else
  begin
    write('O numero digitado nao e maior que zero.');
  end;
end.
