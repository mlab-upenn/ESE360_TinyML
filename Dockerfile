FROM ruby:latest

VOLUME /site

EXPOSE 4000

WORKDIR /site

# RUN apk update && \
#     apk --update add \
#     gcc \
#     g++ \
#     make \
#     git \
#     curl \
#     bison \
#     ca-certificates \
#     tzdata \
#     ruby \
#     ruby-rdoc \
#     ruby-irb \
#     ruby-bundler \
#     ruby-nokogiri \
#     ruby-dev \
#     glib-dev \
#     zlib-dev \
#     libc-dev && \
#     echo 'gem: --no-document' > /etc/gemrc && \
#     gem install github-pages && \
#     gem install jekyll-watch && \
#     gem install jekyll-admin && \
#     apk del gcc g++ binutils bison perl nodejs make curl && \
#     rm -rf /var/cache/apk/*
# ENTRYPOINT [ "/" ]
# CMD ["bundle", "install", "&&", "bundle", "exec", "jekyll", "serve", "--watch", "--force_polling", "--incremental", "--host", "0.0.0.0", "--port", "4000"]

COPY ./ /site/
RUN bundle install
RUN gem install faraday-retry