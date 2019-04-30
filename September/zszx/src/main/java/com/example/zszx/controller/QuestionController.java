package com.example.zszx.controller;

import com.example.zszx.service.QuestionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class QuestionController {

    @Autowired
    QuestionService questService;

    @RequestMapping("/query")
    public @ResponseBody String query(@RequestParam(value = "question") String question) throws Exception {
        return questService.answer(question);
    }
}
