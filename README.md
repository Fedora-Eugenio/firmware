# firmware
## prueba 2
### prueba 3

**lisdf**
* edgsd fg
* sdg sdf g
- dfg sdfg
- dfgh dfg dfh
[url](texto)
*dfjkhgsjdfhgjkshdkfg*

_texto_

` for(;;){

   	switch (estado){
   		
   		case ESPERAR:
   			break;
   			
   		case MEDIR:
   			//CodError = AD1_Measure(TRUE);
   			//CodError = AD1_GetValue16(&Medida); //1111 1111 1111 0000
   			AD1_MeasureChan(TRUE, 0);
   			CodError =  AD1_GetChanValue16(0, &Medida1);
   			AD1_MeasureChan(TRUE, 1);
   			CodError =  AD1_GetChanValue16(1, &Medida2);
   			D1 = Bit1_GetVal();
   			D2 = Bit2_GetVal();
   			D3 = Bit3_GetVal();
   			D4 = Bit4_GetVal();
`

- [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
- [x] list syntax required (any unordered or ordered list supported)
- [x] this is a complete item
- [ ] this is an incomplete item

En la version #1 está el primer commit

First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column
