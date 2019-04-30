package com.example.zszx.controller;

import com.example.zszx.node.Year;
import com.example.zszx.repository.YearRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class YearController {
    @Autowired
    YearRepository yearRepository;
    @RequestMapping("/get/year")
    public List<Year> getYear(@RequestParam(value = "year") String year){
        return yearRepository.findByYear(year);
    }
}
