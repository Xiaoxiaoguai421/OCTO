package com.example.zszx.controller;

import com.example.zszx.node.Score;
import com.example.zszx.repository.ScoreRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
public class ScoreController {
    @Autowired
    ScoreRepository scoreRepository;
    @RequestMapping("/get/score/province")
    public List<Score> getScoreByProvince(@RequestParam(value = "province") String province){
        return scoreRepository.findByProvince(province);
    }

    @RequestMapping("/get/score/subject")
    public List<Score> getScoreBySubject( @RequestParam(value = "subject") String subject){
        return scoreRepository.findBySubject(subject);
    }
}
