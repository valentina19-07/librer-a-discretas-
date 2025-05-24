package com.denkitronik.springbootjni;

import libcodificador.CodificadorCesar;
import org.springframework.web.bind.annotation.*;

@RestController
@CrossOrigin
@RequestMapping("/api/codificador-service")
public class JNIRestController {
    private CodificadorCesar codificadorCesar;

    public JNIRestController() {
        this.codificadorCesar = new CodificadorCesar();
    }

    @GetMapping("/codificar/{mensaje}/{codigo}")
    public String codificar(@PathVariable String mensaje, @PathVariable int codigo){
        return codificadorCesar.codificar(mensaje, codigo);
    }

    @GetMapping("/decodificar/{mensaje}/{codigo}")
    public String decodificar(@PathVariable String mensaje, @PathVariable int codigo){
        return codificadorCesar.decodificar(mensaje, codigo);
    }
}
