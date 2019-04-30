package com.example.zszx.controller;

import com.example.zszx.node.Province;
import com.example.zszx.repository.ProvinceRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class ProvinceController {
    @Autowired
    ProvinceRepository provinceRepository;
    @RequestMapping("/get/province")
    public List<Province> getProvince(@RequestParam(value = "province") String province){
        return provinceRepository.findByProvince(province);
    }
}
