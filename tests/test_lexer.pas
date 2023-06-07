program Exemplo;

var
  numero1, numero2, resultado: integer;

begin
  writeln('Digite o primeiro numero: ');
  readln(numero1);
  
  writeln('Digite o segundo numero: ');
  readln(numero2);
  
  resultado := numero1 + numero2;
  
  writeln('A soma de ', numero1, ' e ', numero2, ' e igual a ', resultado);

end.
