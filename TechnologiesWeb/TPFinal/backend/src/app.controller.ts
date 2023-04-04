import { Controller, Get, Query } from '@nestjs/common';
import { AppService } from './app.service';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get('/update-db')
  updateBd() {
    return this.appService.updateBd();
  }

  @Get('/search')
  search(@Query() query) {
    return this.appService.search(query.query);
  }

  @Get('/documents')
  findAllDocuments() {
    return this.appService.findAllDocuments();
  }

  @Get('/words')
  findAllWords() {
    return this.appService.findAllWords();
  }
}
